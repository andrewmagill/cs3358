#include <iostream>
#include "list_3358_pointers.h"

using namespace std;
using namespace cs3358_LL;

void showList(List_3358 myList);

int main() {
  // test constructor
  List_3358 myList;
  
  // test inserting 
  myList.insert(4);  
  myList.insert(8);  
  myList.insert(3);
  
  showList(myList);
  
  // test reset
  cout << "reset()" << endl;
  myList.reset();
  
  // test getCurrent()
  cout << "getCurrent: " << myList.getCurrent() << endl;
  
  myList.insert(21);
  
  showList(myList);
  
  myList.insert(55);
  
  showList(myList);
  
  // test remove in the middle
  cout << "removing in the middle" << endl;
  myList.remove();
  
  showList(myList);
  
  myList.reset();
  cout << "reset()" << endl;
  
  cout << "removing at the beginning" << endl;
  myList.remove();
  
  showList(myList);
  
  myList.advance();
  myList.advance();
  
  cout << "getCurrent: " << myList.getCurrent() << endl;
  
  cout << "removing at the end" << endl;
  myList.remove();
  
  showList(myList);
}

void showList(List_3358 myList) {
  
  if(myList.isEmpty()) {
   cout << "empty list" << endl;
   return;
  }

  myList.reset();

  while (!myList.atEOL())
  {
    cout << myList.getCurrent() << endl;
    myList.advance();
  }

  cout << endl;
}