//list_test.cpp
//CS3358
//tests a very simple cursor based list ADT

#include <iostream>
#include "list_3358.h"

using namespace std;
using namespace cs3358;

void showList(List_3358 myList);
bool search (List_3358 & myList, List_3358::value_type target);

int main () {
    
   List_3358 myList;

   myList.insert(42);
  
   myList.insert(52);
 
   myList.insert(12);
  
   myList.insert(-42);
   
   myList.insert(2);
  
   myList.reset();
   myList.advance();
   cout << myList.getCurrent()<< endl;
 
   cout << "test inserts" << endl;  
   showList(myList);
   cout << myList.getCurrent()<< endl;
   
   myList.reset();   
   myList.insert(88);
   
   cout << "test inserts" << endl;  
   showList(myList);
   
   
   List_3358 myList2 = myList; //copy constructor

   cout << "mylist 2..." << endl;   
   showList(myList2);

   while (myList.advance());
     
   cout << "test getCurrent at EOL" << endl;
   if (!myList.atEOL())
      cout <<"shouldn't be here..." << myList.getCurrent() << "boo" << endl;
   else
      cout << "at EOL" << endl;
   
   cout << endl;
   myList.reset();
   if (myList.advance())
      cout << myList.getCurrent() << endl;
      
   cout << " test search" << endl;
   if (search(myList,12))
     cout << myList.getCurrent() << endl;
    
   myList.remove();
   
   cout << " test remove after search" << endl;   
   showList(myList);
   
   cout << "show other list, test copy constructor" << endl;
   showList(myList2);
   
   cout << " test search 42" << endl;
   if (search(myList,42))
     cout << myList.getCurrent() << endl;
    
   myList.remove();
   
   cout << " test remove after search" << endl;   
   showList(myList);
   
   myList.remove();
   
   cout << "show other list, test copy constructor" << endl;
   showList(myList2);
 

}   


//prints list.
//note that the cursor is at the EOL when finished
void showList(List_3358 myList) {

   myList.reset();

   while (!myList.atEOL())
   {
      cout << myList.getCurrent() << endl;
      myList.advance();
   }
   
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
