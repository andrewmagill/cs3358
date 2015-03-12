#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <time.h>
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

void showList( MyList & ml ) {
  ml.reset();

  int count = 0;

  while (!ml.atEOL()) {
    cout << "Item " << count << "\t:\t" << ml.getCurrent() << endl;
    ml.advance();
    count++;
  }

  ml.reset();
}

void advanceAll( MyList & ml ) {
  // this is a shitty poopoo method
  int count = 0;

  ml.reset();

  while (!ml.atEOL()) {
    ml.advance();
    count++;
  }

  ml.reset();

  for(int i = 0; i < count-1; i++) {
    ml.advance();
  }
}

int main (int argc, char *argv[]) {
  parseArgs(argc, argv);

  MyList newList;

  cout << "The list is empty: " << isTrue( newList.isEmpty() ) << endl;
  cout << "The cursor is at the end of the list: " << isTrue( newList.atEOL() ) << endl;
  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "--------" << endl;

  int value = 5;

  cout << "Inserting " << value << endl;
  newList.insert(value);

  value = 51;
  cout << "Inserting " << value << endl;
  newList.insert(value);

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "--------" << endl;

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "--------" << endl;

  value = 3;
  cout << "Inserting " << value << endl;
  newList.insert(value);

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "advancing cursor" << endl;
  newList.advance();

  value = 99;
  cout << "Inserting " << value << endl;
  newList.insert(value);

  cout << "--------" << endl;

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "show list: " << endl;
  showList(newList);

  cout << "--------" << endl;

  cout << "advancing to tail" << endl;
  advanceAll(newList);

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "removing last element" << endl;
  newList.remove();

  cout << "show list: " << endl;
  showList(newList);

  cout << "--------" << endl;

  cout << "resetting cursor" << endl;
  newList.reset();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "removing first element" << endl;
  newList.remove();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "show list: " << endl;
  showList(newList);

  cout << "--------" << endl;

  cout << "advancing cursor" << endl;
  newList.advance();

  cout << "Get the value of the element pointed to by the cursor: " << newList.getCurrent() << endl;

  cout << "removing middle element" << endl;
  newList.remove(); // seg fault

  cout << "show list: " << endl;
  showList(newList);

  time_t t;
  cout << endl << "========== time: " << time(&t) << "==========" << endl;

  return EXIT_SUCCESS;
}
