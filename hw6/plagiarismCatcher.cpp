#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct FILE_LOC {
  string path;
  string filename;
};

int get_dir_list(char * dir, vector<FILE_LOC> &files);
int process_files(const vector<FILE_LOC> &files, int chunksize);
string strip_non_alpha(string word);
bool strip_char(char c);
int store_chunk(const list<string> & chunk);

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

  get_dir_list(argv[1], files);
  process_files(files, chunksize);

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

int process_files(const vector<FILE_LOC> &files, int chunksize) {

    ifstream infile;
    string filename;
    string path;
    string word;
    list<string> chunk;

    for (int i = 0; i < files.size(); i++) {
      path = files[i].path;
      filename = files[i].filename;

      cout << "\n++++++++++++++++++++" << endl;
      cout << "+ file index: " << (i-1) << endl;
      cout << "+ file name: " << filename << endl;
      cout << "+ chunk size: " << chunksize << endl;
      cout << "++++++++++++++++++++\n" << endl;

      if( !( (filename == ".") || (filename == "..") ) )
        infile.open(path + filename);

        chunk.clear();

        if ( infile.is_open() )

          while ( infile >> word ) {
            word = strip_non_alpha(word);
            chunk.push_back(word);
            if(chunk.size() >= chunksize) {
              store_chunk(chunk);
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

int store_chunk(const list<string> & chunk) {
  for (list<string>::const_iterator iter = chunk.begin(); iter != chunk.end(); ++iter)
	  cout << (*iter);
  cout << "\n";

  return 0;
}
