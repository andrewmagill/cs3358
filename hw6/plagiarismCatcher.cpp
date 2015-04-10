#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int getdir(char * dir, vector<char *> &files);

int processfile(char * filename, int chunksize);

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

  char * path = argv[1];
  int chunksize = atoi(argv[2]);

  if((chunksize > 40) || (chunksize < 1)) {
    cout << "Sequence length " << chunksize << " is not good, please try again." << endl;
    return -1;
  }

  vector<char *> files = vector<char *>();

  getdir(path, files);

  char * filename;

  for (int i = 0; i < files.size(); i++) {
    filename = files[i];
    if( !( (strncmp(filename, ".")) || (filename == "..") ) )
      processfile(filename, chunksize);
  }

  return 0;
}

int getdir(char * dir, vector<char *> &files) {
  DIR *dp;
  struct dirent *dirp;

  if((dp = opendir(dir)) == NULL) {
    cout << "Error(" << errno << ")" << endl;
    cout << "I don't think \"" << dir << "\" is a valid directory" << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }

  closedir(dp);

  return 0;
}

int processfile(char * filename, int chunksize) {

    cout << filename << endl;

    return 0;
}
