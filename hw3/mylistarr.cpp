#include "list_3358_arrays.h"
#include <iostream>

using namespace std;
using namespace cs3358;

// constructors

List_3358::List_3358 ( ) {
  currentSize = 0;
  cursor = 0;
}

List_3358::List_3358 ( const List_3358 & src ) {
  currentSize = src.currentSize;
  cursor = src.cursor;
  
  for (int i = 0; i < currentSize; i++)
    values[i] = src.values[i];
}

// mutators

void List_3358::insert ( const value_type & item ) {

}
  
void List_3358::remove ( ) {

}
    
void List_3358::reset ( ) {

}
      
bool List_3358::advance ( ) {

}

// accessors

bool List_3358::isEmpty ( ) const {

}

bool List_3358::atEOL ( ) const {

}

bool List_3358::isFull ( ) const {

}

List_3358::value_type List_3358::getCurrent ( ) const {

}