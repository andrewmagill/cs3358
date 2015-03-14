#ifndef STACK_3358_H
#define STACK_3358_H

#include "List_3358.h"

using namespace std;
using namespace cs3358_LL;

template<class ItemType>
class Stack_3358 {
  public:

    typedef int size_type;

    Stack_3358();
    Stack_3358(const Stack_3358 & src);

    void makeEmpty();
    void push(const ItemType &);
    ItemType pop();

    bool isEmpty() const;
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

  try
  {
    //Node*  listNode = new Node(value);
    // guaranteed to be a good alloc if we reach here
    //  if it was a bad alloc, we go to our catch
    return true;
  }
  catch(std::bad_alloc& exc)
  {
    return false;
  }
}
