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

using namespace std;

struct FILE_LOC {
  string path;
  string filename;
};

int get_dir_list(char * dir, vector<FILE_LOC> &files);
bool process_files(const vector<FILE_LOC> &files, int chunksize, HashMap & map);
string strip_non_alpha(string word);
bool strip_char(char c);
bool store_chunk(const list<string> & chunk, HashMap & map, int i);
int reduce(HashMap & map);

int main(int argc, char *argv[]) {
  if(argc < 3) {
      cout << "Error: Missing Parameters\n\n";
      cout << "Please provide a path containing documents to analyze, ";// << endl;
      cout << "and an \ninteger representing the length of the words ";// << endl;
      cout << "sequences to compare.\n\n";
      cout << "Example: \n";
      cout << "prompt> ./plagiarismCatcher path/to/text/files 6\n";
      return 0;
  }

  int chunksize = atoi(argv[2]);

  if((chunksize > 40) || (chunksize < 1)) {
    cout << "Sequence length " << chunksize << " is not good, please try again." << endl;
    return -1;
  }

  vector<FILE_LOC> files = vector<FILE_LOC>();

  HashMap * map = new HashMap();

  get_dir_list(argv[1], files);
  process_files(files, chunksize, * map);
  reduce(* map);
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

bool process_files(const vector<FILE_LOC> &files, int chunksize, HashMap & map) {
    string filename;
    string path;
    string word;
    list<string> chunk;

    //HashMap * map = new HashMap();

    for (int i = 0; i < files.size(); i++) {
      path = files[i].path;
      filename = files[i].filename;

      path = path + filename;

      ifstream infile(path.c_str());

      if( (filename == ".") || (filename == "..") )
        continue;
    /*
      cout << "\n++++++++++++++++++++" << endl;
      cout << "+ file index: " << (i-1) << endl;
      cout << "+ file name: " << filename << endl;
      cout << "+ chunk size: " << chunksize << endl;
      cout << "++++++++++++++++++++\n" << endl;
    */
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

    return 0;
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
  //map.insert("hello world", i);

  return true;
}

int reduce(HashMap & map) {
    for(int i = 0; i < map.size(); i++) {
        List_3358<int> bucket = map[i];

        if(!bucket.isEmpty())
            cout << "hash key: " << i << endl;

        bucket.reset();

        while(!bucket.atEOL()) {
            int val = bucket.getCurrent();
            if (val > 0)
                cout << "\tdoc: " << bucket.getCurrent() << endl;
            bucket.advance();
        }


        if(!bucket.isEmpty())
            cout << endl;
    }
    return 0;
}
