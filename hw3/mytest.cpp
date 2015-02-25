#include <iostream>
#include "list_3358_arrays.h"

using namespace std;
using namespace cs3358;

int main() {

  List_3358 myList;
  
  myList.advance();
  
  cout << "is empty: " << myList.isEmpty() << endl;
  
  cout << "is at end of list: " << myList.atEOL() << endl;
  
  cout << "get current (may be invalid): " << myList.getCurrent() << endl;
  
  myList.reset();
  
  cout << "is empty: " << myList.isEmpty() << endl;
  
  myList.insert(5);
  myList.insert(4);
  myList.insert(3);
  myList.insert(2);
  myList.insert(1);
  
  myList.reset();
  
  cout << "get current (may be invalid): " << myList.getCurrent() << endl;

  myList.advance();
  myList.advance();
  
  cout << "get current (may be invalid): " << myList.getCurrent() << endl;
  
  return 0;
}