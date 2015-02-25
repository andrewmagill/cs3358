#include <iostream>
#include "list_3358_arrays.h"

using namespace std;
using namespace cs3358;

int main() {

  List_3358 myList;
  
  myList.advance();
  
  cout << "is empty: " << myList.isEmpty() << endl;
  
  cout << "is at ed of list: " << myList.atEOL() << endl;
  
  cout << "get current (may be invalid): " << myList.getCurrent() << endl;
  
  myList.reset();
  
  cout << "is empty: " << myList.isEmpty() << endl;
  
  return 0;
}