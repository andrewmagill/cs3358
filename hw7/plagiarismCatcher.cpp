//////////////////////////////////////////
// CS 3358 Section 152 Spring 2015
// Dr. Priebe
// HW 6, Part 1
// 05/09/2015
//
// Andrew Magill
// a_m730
//
// program acepts command line arguments:
// arg[1] = path, arg[2] = n
// reads each file in given directory,
// finds all consecutive n word sequences
// output to console - AND - write to file
// * I wasn't sure if I should write out
// * to a file (processed_chunks.txt), it
// * can get pretty big
//////////////////////////////////////////

#include <algorithm>
#include <cstdlib>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "HashMap.h"
#include "sorting.h"

#include <ctime>

using namespace std;

struct FILE_LOC {
  string path;
  string filename;
};
/*
struct RESULT {
    string file_a;
    string file_b;
    int collisions;
};
*/
int get_dir_list(char * dir, vector<FILE_LOC> &files);
int process_files(const vector<FILE_LOC> &files, int chunksize, HashMap & map);
string strip_non_alpha(string word);
bool strip_char(char c);
bool store_chunk(const list<string> & chunk, HashMap & map, int i);
vector<RESULT> reduce(HashMap & map, vector<vector<int> > matrix, vector<FILE_LOC> files);

int main(int argc, char *argv[]) {
    //
    clock_t start;
    double duration;
    start = clock();
    //

    if(argc < 4) {
        cout << "Error: Missing Parameters\n\n";
        cout << "Please provide a path containing documents to analyze, ";// << endl;
        cout << "an \ninteger representing the length of the words ";// << endl;
        cout << "sequences to \ncompare, and a minimum similarity threshold.\n\n";
        cout << "Example: \n";
        cout << "prompt> ./plagiarismCatcher path/to/text/files 6 200\n";
        return 0;
    }

    int chunksize = atoi(argv[2]);

    if((chunksize > 40) || (chunksize < 1)) {
        cout << "Sequence length " << chunksize << " is not good, please try again." << endl;
        return true;
    }

    int threshold = atoi(argv[3]);

    vector<FILE_LOC> files = vector<FILE_LOC>();

    HashMap * map = new HashMap();

    get_dir_list(argv[1], files);
    int fileCount = process_files(files, chunksize, * map);

    vector<int> columns(fileCount, 0);
    vector<vector<int> > matrix(fileCount,columns);

    vector<RESULT> results = reduce(* map, matrix, files);
    Sorting::quicksort(results,0,results.size());

    for(int i=0; i<results.size(); i++) {
        if(results[i].collisions > threshold) {
            cout << "Files: " << results[i].file_a << " and " << results[i].file_b;
            cout << " have a similarity score of " << results[i].collisions << endl;
        }
    }

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << duration << endl;

    return 0;
}

int get_dir_list(char * dir, vector<FILE_LOC> &files) {
  DIR *dp;
  struct dirent *dirp;

  if((dp = opendir(dir)) == NULL) {
    cout << "Error(" << errno << ")" << endl;
    cout << "I don't think \"" << dir << "\" is a valid directory" << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    FILE_LOC file_location;
    file_location.path = string(dir);
    file_location.filename = string(dirp->d_name);
    files.push_back(file_location);
  }

  closedir(dp);

  return 0;
}

int process_files(const vector<FILE_LOC> &files, int chunksize, HashMap & map) {
    string filename;
    string path;
    string word;
    list<string> chunk;

    for (int i = 0; i < files.size(); i++) {
      path = files[i].path;
      filename = files[i].filename;

      path = path + "/" + filename;

      ifstream infile(path.c_str());

      if( (filename == ".") || (filename == "..") )
        continue;

      chunk.clear();

      if ( infile.is_open() )

        while ( infile >> word ) {
          word = strip_non_alpha(word);
          chunk.push_back(word);

          if(chunk.size() >= chunksize) { // shouldn't ever be > than

            store_chunk(chunk, map, i);

            chunk.pop_front();
          }
        }

        infile.close();
      }

    return files.size();
}

string strip_non_alpha(string word) {
  word.erase(std::remove_if(word.begin(), word.end(), strip_char), word.end());
  return word;
}

bool strip_char(char c) {
  return !isalpha(c);
}

bool store_chunk(const list<string> & chunk, HashMap & map, int i) {
  string chunkString = "";

  for (list<string>::const_iterator iter = chunk.begin(); iter != chunk.end(); ++iter) {
    chunkString += *iter;
  }

  map.insert(chunkString, i);

  return true;
}

vector<RESULT> reduce(HashMap & map, vector<vector<int> > matrix, vector<FILE_LOC> files) {

    vector<RESULT> results = vector<RESULT>();

    for(int i = 0; i < map.size(); i++) {
        List_3358<int> bucket = map[i];
        bucket.reset();

        while(!bucket.atEOL()) {
            int doc_a = bucket.getCurrent();
            bucket.remove();
            while(!bucket.atEOL()) {
                int doc_b = bucket.getCurrent();
                if(doc_a != doc_b) {
                    matrix[doc_a][doc_b] += 1;
                }
                bucket.advance();
            }
            bucket.reset();
        }
    }

    for(int i = 2; i < matrix.size(); i++) {
        for (int j = i+1; j < matrix.size(); j++) {
            int collisions = matrix[i][j];
            if(collisions > 0) {
                RESULT result;
                result.file_a = files[i].filename;
                result.file_b = files[j].filename;
                result.collisions = collisions;
                results.push_back(result);
            }
            //cout << matrix[i][j] << "\t";
        }
        //cout << "\b" << endl;
    }

    return results;
}
