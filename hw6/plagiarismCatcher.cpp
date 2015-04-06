#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getdir(char * dir, vector<string> &files);

int main(int argc, char *argv[]) {

  vector<string> files = vector<string>();

  getdir(argv[1],files);

  for (int i = 0; i < files.size(); i++) {
    cout << i << files[i] << endl;
  }

  return 0;
}

int getdir(char * dir, vector<string> &files) {
  DIR *dp;
  struct dirent *dirp;

  if((dp = opendir(dir)) == NULL) {
    cout << "Error(" << errno << ")" << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }

  closedir(dp);
  return 0;
}
