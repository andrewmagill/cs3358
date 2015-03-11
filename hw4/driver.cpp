#include <stdlib.h>
#include <iostream>
#include "mylist.h"

using namespace std;

int main (int argc, char *argv[]) {
  if (argc > 2)
    cout << "Too many arguments";
  else if (argc == 2)
    cout << argv[1] << endl;
  else
    cout << "No arguments" << endl;

  return EXIT_SUCCESS;
}
