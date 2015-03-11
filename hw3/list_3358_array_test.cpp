#include <iostream>
#include "list_3358_arrays.h"

using namespace std;
using namespace cs3358;

void showList(List_3358 myList);
bool search (List_3358 & myList, List_3358::value_type target);

int main() {

  // test constructor
  List_3358 myList;
  
  // test insert
  myList.insert(9);
  cout << "inserting 9" << endl;
  cout << "myList:" << endl;
  showList(myList);  
  
  // test remove
  // this is removing from the end of the array 
  // and the end of the list  
  myList.remove();  
  cout << "removing item that is at the end of the array and at the end of the list" << endl;
  cout << "myList: (should be empty)" << endl;
  showList(myList);
  
  // add a few items then remove one
  myList.insert(36);
  cout << "inserting 36" << endl;
  myList.insert(13);
  cout << "inserting 13" << endl;
  myList.insert(24);
  cout << "inserting 24" << endl;
  cout << "myList:" << endl;  
  showList(myList);
    
  //myList.showList();
  
  cout << "removing item that is at the end of the array and at the end of the list" << endl;
  myList.remove();
  cout << "myList:" << endl;
  showList(myList);  
  
  // test reset
  cout << "resetting cursor" << endl;
  myList.reset();
  
  // test inserting in the front of the list
  cout << "inserting at the beginning of the list" << endl;
  myList.insert(99);
  cout << "myList:" << endl;
  showList(myList);
  
  // test inserting in the middle of the list
  cout << "inserting in the middle of the list of the list" << endl;
  myList.insert(58);
  showList(myList);
  
  cout << "myList.getCurrent(): " << myList.getCurrent() << endl;
  
  cout << "removing item that is not at the end of the array, and not the end of the list" << endl;
  myList.remove();
  showList(myList);
  
  //myList.showList();
  
  // advancing to the end of the list
  cout << "advancing to the end of the list" << endl << endl;
  do 
  {
    cout << "myList.getCurrent() " << myList.getCurrent() << endl;
    myList.advance();
    cout << "myList.advance() " << endl;
  } while (!myList.atEOL());
  cout <<  endl;
  
  //myList.showList();
  
  cout << "myList.atEOL(): " << myList.atEOL() << endl;
  
  // test removing item that is at the end of this list, but not at the end of the array
  cout << "removing item that is at the end of the list, but not at the end of the array" << endl;
  myList.remove();
  
  showList(myList);
  
  //myList.showList();
  
  // finally removing from the end of the array, not the end of the list
  myList.reset();
  
  cout << "removing from the end of the array, but not the end of the list" << endl;
  myList.remove();
    
  showList(myList);
  
  // test the copy constructor
  List_3358 copyList = myList;
  
  copyList.insert(75);
  
  cout << "copyList: "<< endl;
  showList(copyList);
  
  cout << "myList: "<< endl;
  showList(myList);
  
  return 0;
}


//prints list.
//note that the cursor is at the EOL when finished
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

//if found, places the cursor at the target and returns true
//otherwise returns false
bool search (List_3358 & myList, List_3358::value_type target) {

  bool found = false;

  myList.reset();

  while (!found && !myList.atEOL())
  {
    if (target == myList.getCurrent())
       found = true;
    else
       myList.advance();
  }

  return found;
    
}