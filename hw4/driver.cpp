#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include "mylist.h"

using namespace std;
using namespace cs3358;

void parseArgs (int argc, char *argv[]) {
  if (argc > 2)
    cout << "Too many arguments";
  else if (argc == 2)
    cout << argv[1] << endl;
  else
    //cout << "No arguments" << endl;
    assert(1);
}

string isTrue(int test) {
  if(test)
    return "True";
  else
    return "False";
}

int main (int argc, char *argv[]) {
  parseArgs(argc, argv);

  MyList newList;

  cout << "The list is empty: " << isTrue( newList.isEmpty() ) << endl;
  cout << "The cursor is at the end of the list: " << isTrue( newList.atEOL() ) << endl;
  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "Inserting new node" << endl;
  newList.insert(5);

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  return EXIT_SUCCESS;
}
