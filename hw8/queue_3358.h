
/*  queue_3358.h
  CS 3358 Fall 2008

  a very simple array-based queue ADT

  This implentation will use a dynamic array

  Note that this implementation uses one extra space and is a circular queue.

*/

#ifndef QUEUE_3358_H
#define QUEUE_3358_H

#include <cstdlib>  // Provides size_t
#include <assert.h>

using namespace std;

template<class ItemType>
class Queue_3358 {
 public:

    typedef int value_type;
    typedef int size_type;


    //Default constructor will default to MAX_ITEMS in queue
    Queue_3358();

    //Constructor with size of queue
    Queue_3358(int max);

    //Copy constructor
    Queue_3358(const Queue_3358 & src);

    //Destructor
    ~Queue_3358();

/****************************
makeEmpty

Function: Removes all the items from the queue.
Preconditions: queue has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items on the queue.
Preconditions: queue has been initialized
Postconditions: Returns true if there are no items on the queue, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the queue
Preconditions: queue has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
push

Function: Adds newItem to the top of the queue.
Preconditions: queue has been initialized and is not full.
Postconditions: newItem is at the top of the queue.
*****************************/
 	void enQueue(const ItemType &);

/****************************
pop

Function: Removes first item from queue and returns it.
Preconditions: queue has been initialized and is not empty.
Postconditions: First element has been removed from queue and is returned.
*****************************/
    ItemType deQueue();


 private:
    size_type front;
    size_type rear;
    ItemType* items;  //dynamic array
    size_type maxQue; //will be one bigger than the size in the constructor

    static const int MAX_ITEMS = 1000;

};

/*******************************
/ Function implementations
********************************/

template<class ItemType>
Queue_3358<ItemType>::Queue_3358 ()
{
  maxQue = MAX_ITEMS + 1;  //default value if none provided
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];   //dynamically allocated
}

template<class ItemType>
Queue_3358<ItemType>::Queue_3358(int max)
{

  maxQue = max + 1;   //max provided by user
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];  //dynamically allocated
}

template<class ItemType>
Queue_3358<ItemType>::Queue_3358(const Queue_3358 & src)
{



}


template<class ItemType>
Queue_3358<ItemType>::~Queue_3358()
{
  delete [] items;
}


template<class ItemType>
void Queue_3358 <ItemType>::makeEmpty()
{


}


template<class ItemType>
bool Queue_3358 <ItemType>::isEmpty() const
{
    // not yet implemented
    return false;
}

template<class ItemType>
bool Queue_3358 <ItemType>::isFull() const
{
    // not yet implemented
    return false;
}


template<class ItemType>
void Queue_3358 <ItemType>::enQueue(const ItemType& newItem)
{
   assert(!isFull());

   items[rear] = newItem;
   rear--;
}


template<class ItemType>
ItemType Queue_3358 <ItemType>::deQueue()
{
   assert(!isEmpty());


}


#endif
