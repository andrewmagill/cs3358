#ifndef STACK_3358_H
#define STACK_3358_H

#include "List_3358.h"

using namespace std;
using namespace cs3358_LL;

template<class ItemType>
class Stack_3358 {
  public:

    // constructor - default
    Stack_3358();

    // constructor - copy
    Stack_3358(const Stack_3358 & src);

    /****************************
    makeEmpty

    Function: Removes all the items from the stack.
    Preconditions: Stack has been initialized
    Postconditions: All the items have been removed
    *****************************/
    void makeEmpty();

    /****************************
    push

    Function: Adds newItem to the top of the stack.
    Preconditions: Stack has been initialized and is not full.
    Postconditions: newItem is at the top of the stack.
    *****************************/
    void push(const ItemType &);

    /****************************
    pop

    Function: Removes topItem from stack and returns it.
    Preconditions: Stack has been initialized and is not empty.
    Postconditions: Top element has been removed from stack and item is a copy of the removed element.
    *****************************/
    ItemType pop();

    /****************************
    isEmpty

    Function: Checks to see if there are any items on the stack.
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there are no items on the stack, else false.
    *****************************/
    bool isEmpty() const;

    /****************************
    isFull

    Function: Determines if you have any more room to add items to the stack
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there is no more room to add items, else false
    *****************************/
    bool isFull() const;

  private:

    List_3358<ItemType> list;

    struct Node {
      ItemType value;
      Node *next;
    };

    Node *head;
};

#endif

// constructors

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ( ) { }

template<class ItemType>
Stack_3358<ItemType>::Stack_3358 ( const Stack_3358 & src ) { }

// mutators

template<class ItemType>
void Stack_3358 <ItemType>::makeEmpty() {
  while(!list.isEmpty()) {
    list.remove();
  }
}

template<class ItemType>
void Stack_3358 <ItemType>::push(const ItemType& newItem) {
  if(!list.atEOL()) {
    while(!list.atEOL()) {
      list.advance();
    }
  }
  list.insert(newItem);
}

template<class ItemType>
ItemType Stack_3358 <ItemType>::pop() {
  if (!list.isEmpty()) {
    if (list.atEOL())
      list.regress();

    ItemType value = list.getCurrent();
    list.remove();

    return value;
  }

  ItemType dummyval;
  return dummyval;
}

// accessors

template<class ItemType>
bool Stack_3358 <ItemType>::isEmpty() const {
  return list.isEmpty();
}

template<class ItemType>
bool Stack_3358 <ItemType>::isFull() const {
  return false;
}
