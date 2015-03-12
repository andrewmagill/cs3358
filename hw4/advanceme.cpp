#include <iostream>
#include "mylist.h"

using namespace std;
using namespace cs3358;

int main() {
  MyList newList;
  newList.insert(4);
  newList.insert(49);
  newList.insert(2);
  newList.insert(567);

  newList.reset();

  while(!newList.atEOL()) {
    cout << newList.getCurrent() << endl;
    newList.advance();
  }

  cout << endl;

  newList.reset();

  // i did this in the test, dang it, so stupid
  while(newList.advance()) {
    cout << newList.getCurrent() << endl;
  }

  return 0;
}
