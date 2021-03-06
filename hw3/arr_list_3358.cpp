//list_3358.cpp
//implementation of a very simple curssor-based List ADT
//This is a simple array implementation

#include "arr_list_3358.h"
#include <iostream>


using namespace std;
using namespace cs3358;     
      
List_3358::List_3358 ( ) {
   currentSize = 0;
   cursor = 0;
}      

List_3358::List_3358 ( const List_3358 & src ) {

   currentSize = src.currentSize;
   cursor = src.cursor;

   for (int i = 0 ; i < currentSize; i++)
      values[i] = src.values[i];
}


List_3358::~List_3358 ( ) {

}

//************************************
//Mutator(s)

void List_3358::insert (const value_type & item) {

   if (!isFull())
   {
      if (atEOL())
      {
         values[cursor] = item;
         currentSize++;
         cursor++;
      }
      else
      {
         for (int i = currentSize; i > cursor; i--)
            values[i] = values[i-1];
         values[cursor] = item;
         currentSize++;
      }
    }

}        



void List_3358::remove() {

   if (!atEOL() && !isEmpty())
   {
      for (int i = cursor; i < currentSize - 1; i++)
         values[i] = values[i+1];

      currentSize--;
   }

}


void List_3358::reset ( ) {

   cursor = 0;

}



bool List_3358::advance ( ) {

   if (atEOL())
   {
      return false;
   }
   else
   {
      cursor++;
   }

   return (!atEOL());

}



//*******************
// Accessor(s)


bool List_3358::isEmpty ( ) const {

   return (currentSize == 0);

}



bool List_3358::atEOL ( ) const {

   return (cursor == currentSize);   
}





bool List_3358::isFull ( ) const {

   return (currentSize == MAX_ITEMS);
}



List_3358::value_type List_3358::getCurrent ( ) const {
   if(!atEOL())
      return values[cursor];         
}




