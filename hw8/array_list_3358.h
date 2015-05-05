/*  list_3358.h
  CS 3358 Spring 2008
  updated Spring 2009 and Fall 2009

  a very simple cursor based List ADT

  This implentation will use a simulated doubly-linked list that uses arrays.

  The constant EOL will be assinged the value -1 and signifies the end of the list
  and the beginning of the list.

  We will not use user-defined templates for this program.

    -It is homogenious -- the elements in the collection are all of the same type.
    -It has a finite length (the number of elements).
    -The elements are arranged sequentially:
          o There is a first element and a last element
          o Every element except the last has a unique successor
          o Every element except the first has a unique predecessor
*/

#ifndef LIST_3358_H
#define LIST_3358_H

#include <cstdlib>  // Provides size_t


using namespace std;


namespace cs3358 {
 class List_3358
 {

   public:

      typedef int value_type;  //change here for different data type
      typedef int size_type;
      static const size_type MAX_ITEMS = 100; // a named constant specifying the maximum number of items in a list.
      static const size_type EOL = -1;
      static const size_type BOL = -1;


      //Constructor/Destructor
      //Preconditions: None.
      //Postconditions: Creates an empty list capable of holding Item type data items.
      //Current position is at BOL/EOL.
      //The List has a capacity of at most MAX_ITEMS items.

      List_3358 ( );

      //Preconditions: None
      //Postconditions: Creates a new List which is a deep copy of the passed src List.
      //Implement the copy constructor last, after the rest of the implementation has been debugged.

      List_3358 ( const List_3358 & src );

      //Preconditions: None.
      //Postconditions: Destroys the list, cleaning up all resources associated with the object.

      ~List_3358 ( );


      //************************************
      //Mutator(s)

      //Preconditions: List is not full (i.e. the number of items currently in the list is less than its capacity).
      //Postconditions: The item has been inserted by copying into the list.
      //Location of the insert occurs at the current position (the item previously at the current position
      // is moved to the next position in the list).
      //After an insert, the current position remains the same.
      //If the current position is at the end of the list, the current position will remain
      //at the end of the list after the insert.

      void insert ( const value_type & item );


      //Preconditions: Current position is not EOL and list is not empty.
      //Postconditions: The item at the current position is removed from the list.
      //The current position becomes that of the item's successor,
      //or EOL if the removed item were the last in the list.

      void remove ( );


      //Preconditions: None.
      //Postconditions: Resets the current position to the beginning of the list BOL.
      //If the list is empty, then the position is set to EOL.

      void reset ( );


      //Preconditions: None.
      //Postconditions: Advances the current position to the next item in the list.
      //Advancing from EOL leaves the current position at EOL.
      //If the position following the advance is not EOL, the result of the function is TRUE,
      //and if the position following the advance is EOL, the result of the function is FALSE.

      bool advance ( );



      //*******************
      // Accessor(s)

      //Preconditions: None.
      //Postconditions: Return value is true if the list contains no items, and false otherwise.

      bool isEmpty ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the current position is logically at EOL,
      //and false otherwise.

      bool atEOL ( ) const;


      //Preconditions: None.
      //Postconditions: Return value is true if the list contains its capacity of items,
      //and false otherwise.

      bool isFull ( ) const;



      //Preconditions: Current position is not EOL or at BOL.
      //Postconditions: Return value is a copy of the item at the current position.
      //The list is unaffected.

       value_type getCurrent ( ) const;

       /*
       void showInternalState() const;
       */

   private:

      value_type values[MAX_ITEMS];
      size_type next[MAX_ITEMS];
      size_type previous[MAX_ITEMS];

      size_type currentSize;
      size_type head;
      size_type tail;
      size_type cursor;
 };
}

#include <iostream>

using namespace std;
using namespace cs3358;

// constructors

List_3358::List_3358 ( ) {
  currentSize = 0;
  head = -1;
  cursor = -1;
  tail = -1;
}

List_3358::List_3358 ( const List_3358 & src ) {
  currentSize = src.currentSize;
  head = src.head;
  cursor = src.cursor;
  tail = src.tail;

  for (int i = 0; i < currentSize; i++) {
    next[i] = src.next[i];
    values[i] = src.values[i];
    previous[i] = src.previous[i];
  }
}

List_3358::~List_3358 ( ) {

}

// mutators

void List_3358::insert ( const value_type & item ) {
  if(isFull())
    return; // can't insert if list is full

  int nextIndex = -1;
  int insertIndex = -1;
  int previousIndex = -1;

  int insertionIndex = currentSize;
  values[insertionIndex] = item;

  if(atEOL()) {

    // we're inserting at the end of the list

    // we need to:
    // * set the inserted item's next pointer to -1
    //
    // * set the inserted item's previous pointer to the item logically before us
    //     previous[<insertion index>] = previous[cursor]
    //
    // - we don't need to point the next item to us, because there is no next item
    //
    // * set the previous item's next pointer to us
    //     next[previous[<insertion index>]] = <insertion index>
    //
    // * set the tail to the insertion index (we don't need to do anything with the head)
    //
    // * increment the current size

    next[insertionIndex] = -1;

    if(isEmpty()) {
      previous[insertionIndex] = -1;
      head = insertionIndex;
    }
    else {
      previous[insertionIndex] = tail;
    }

    next[tail] = insertionIndex;

    tail = insertionIndex;

  } else if (cursor == head) {

    // we're inserting at the front of the list

    // we need to:
    // * set the inserted item's next pointer to the head
    //     next[<insertion index>] = head
    //
    // * set the previous pointer to -1
    //
    // - we don't need to point the previous item to us, because there is not previous item
    //
    // * set the next item's previous pointer to us
    //     previous[head] = <insertion index>
    //
    // * set the head to the insertion index
    //
    // * increment the current size

    next[insertionIndex] = head;
    previous[insertionIndex] = -1;
    previous[head] = insertionIndex;
    head = insertionIndex;

  } else {

    // we're inserting in the middle of the list

    // we need to:
    // * set the inserted item's next pointer to the cursor,
    //   because we insert before the cursor
    //     next[<insertion index>] = cursor
    //
    // * set the inserted item's previous pointer to the item logically before us
    //     previous[<insertion index>] = previous[cursor]
    //
    // * set the next item's previous pointer to us
    //     previous[cursor] = <insertion index>
    //
    // * set the previous item's next pointer to us
    //     next[previous[<insertion index>]] = <insertion index>
    //
    // - we don't do anything with the head or the tail
    //
    // * increment the current size

    next[insertionIndex] = cursor;
    previous[insertionIndex] = previous[cursor];
    previous[cursor] = insertionIndex;
    next[previous[insertionIndex]] = insertionIndex;
  }

  currentSize++;
}

void List_3358::remove ( ) {
  if(isEmpty())
    return; // if the list is empty you don't need to do anything

  int deletionIndex;

  if(atEOL()) {
    deletionIndex = currentSize - 1;
  } else {
    deletionIndex = cursor;
  }

  if(((cursor == tail)||(atEOL()))&&(tail == (currentSize - 1))) {

    // if removing from the end of the array and the end of the list, you need to:
    // * set the next pointer of the previous item in the list to -1
    // * set the tail to the previous item in the list
    // * set the cursor to the tail
    // * decrement current size

    next[previous[deletionIndex]] = -1;
    tail = previous[deletionIndex];
    cursor = tail;
    currentSize--;

  } else if(((cursor == tail)||(atEOL()))&&(tail != (currentSize - 1))) {

    deletionIndex = tail;

    // if removing from the end of the list but not the end of the array, you need to:
    // * overwrite the element being removed with the last element of the array
    //
    // * point list item previous to the array's last item to the deletionIndex
    // * point the list item after the array's last item to the deletionIndex
    //
    // * point the tail to the list item before the item being removed
    //
    // * and decrement the current size

    int lastItemIndex = currentSize - 1;
    int lastItemsPreviousIndex = previous[lastItemIndex];
    int lastItemsNextIndex = next[lastItemIndex];

    // set the tail to the next to last item in the list, before you overwrite it
    tail = previous[deletionIndex];
    next[tail] = -1;
    previous[tail] = deletionIndex;
    // set the head, if it's the last item in the array
    if(head == lastItemIndex)
      head = deletionIndex;

    // overwrite item being removed with last physical item in the list
    next[deletionIndex] = next[lastItemIndex];
    values[deletionIndex] = values[lastItemIndex];
    previous[deletionIndex] = previous[lastItemIndex];

    // set the NEXT POINTER for item logically before the last physical item
    if(lastItemsPreviousIndex >= 0)
      next[lastItemsPreviousIndex] = deletionIndex;
    // set the PREVIOUS POINTER for item logically after the last physical item
    if(lastItemsPreviousIndex >= 0)
      previous[lastItemsNextIndex] = deletionIndex;

    currentSize--;
  } else if(cursor == currentSize - 1) {

    // if removing from not the end of the array but not the end of the list, you need to:
    // * set the next pointer of the previous item in the list to the next next pointer
    // * set the previous pointer of the next item to the previous previous pointer
    // * set the cursor to the next next pointer
    // * point the head to the cursor -if- the last physical element was the first logical element
    // * and decrement the current size

    next[previous[deletionIndex]] = next[deletionIndex];
    previous[next[deletionIndex]] = previous[deletionIndex];
    cursor = next[deletionIndex];

    if(head == deletionIndex)
      head = next[deletionIndex];

    currentSize--;
  } else {

    // if removing from not the end of the array and not the end of the list, you need to:
    //
    // * point the list item previous to the one being deleted to the deleted's next pointer
    // * point the list item after the one being deleted to the deleted's previous point
    //
    // * overwrite the element being removed with the last element of the array
    //
    // * point list item previous to the array's last item to the deletionIndex
    // * point the list item after the array's last item to the deletionIndex
    //
    // * set the cursor to the next next pointer
    //
    // - do nothing with the head or the tail
    //
    // * and decrement the current size

    // point items adjacent to the deleted item to each other
    next[previous[deletionIndex]] = next[deletionIndex];
    previous[next[deletionIndex]] = previous[deletionIndex];

    // overwrite
    int lastItemIndex = currentSize - 1;
    int lastItemsPreviousIndex = previous[lastItemIndex];
    int lastItemsNextIndex = next[lastItemIndex];

    next[deletionIndex] = lastItemsNextIndex;
    values[deletionIndex] = values[lastItemIndex];
    previous[deletionIndex] = lastItemsPreviousIndex;

    // point to the array's last item in it's new sport
    next[lastItemsPreviousIndex] = deletionIndex;
    previous[lastItemsNextIndex] = deletionIndex;

    currentSize--;
  }
}

void List_3358::reset ( ) {
  cursor = head;
}

bool List_3358::advance ( ) {
  if (atEOL()) {
    return false;
  } else {
    cursor = next[cursor];
  }

  return (!atEOL());
}

// accessors

bool List_3358::isEmpty ( ) const {
  return (currentSize == 0);
}

bool List_3358::atEOL ( ) const {
  //return ((cursor == currentSize)||(cursor < 0));
  return (cursor < 0);
}

bool List_3358::isFull ( ) const {
  return (currentSize == MAX_ITEMS);
}

List_3358::value_type List_3358::getCurrent ( ) const {
  if(!atEOL())
    return values[cursor];

  value_type dummy;
  return dummy;
}

/*
void List_3358::showInternalState() const {
  cout << "INDEX \t\t ";
  for(int i = 0; i < currentSize; i++)
  {
    cout << "\t" << i;
  }
  cout << endl;

  cout << "NEXT \t\t[";
  for(int i = 0; i < currentSize; i++)
  {
    cout << "\t" << next[i];
  }
  cout << "\t]" << endl;

  cout << "VALUES \t\t[";
  for(int i = 0; i < currentSize; i++)
  {
    cout << "\t" << values[i];
  }
  cout << "\t]" << endl;

  cout << "PREVIOUS \t[";
  for(int i = 0; i < currentSize; i++)
  {
    cout << "\t" << previous[i];
  }
  cout << "\t]" << endl << "cursor = " << cursor << endl;
  cout << "head: " << head << endl << endl;
}
*/

#endif
