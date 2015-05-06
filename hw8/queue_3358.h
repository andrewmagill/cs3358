
/*  queue_3358.h
  CS 3358 251 Spring 2015
  Andrew Magill
  header and partial implementation by Dr. Priebe

  a very simple array-based queue ADT
  (not so simple for me to figure out)

  This implentation will use a dynamic array

  Note that this implementation uses one extra space and is a circular queue.

  The extra space is important! We create an array of max + 1 items, which we
  never completetly fill (we fill at most max elements of the array of size
  max + 1). This situation prevents ambiguity when front == rear. We know when
  front == rear that the queue must be empty.  The queue is full when all but
  one element contains a value.  Here is how we find the size:

      if front <= rear:
          size = rear - front
      else if front > rear:
          size = rear + max - front

  If we allowed the array to fill completetly, front == rear could mean that the
  queue is full or it could mean that the queue is empty.  Not being able to tell
  would prevent us from enqueueing a single item.

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

/****************************
size

Function: Calculates size given relative position and difference between
          front and rear indices.
Preconditions: queue has been initialized
Postconditions: Returns an integer representing number of items
                currently in the queue.
*****************************/
    int size() const;

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
    front = src.front;
    rear = src.rear;
    maxQue = src.maxQue;

    // there's probably a more clever way to do this
    for(int i = 0; i< maxQue; i++) {
        items[i] = src.items[i];
    }
}


template<class ItemType>
Queue_3358<ItemType>::~Queue_3358()
{
    delete [] items;
}

template<class ItemType>
void Queue_3358 <ItemType>::makeEmpty()
{
    while(!isEmpty()) {
        deQueue();
    }

}

template<class ItemType>
int Queue_3358<ItemType>::size() const {
    int size;

    if (front <= rear)
        size = rear - front;
    else if (front > rear)
        size = rear + maxQue - front;

    return size;
}

template<class ItemType>
bool Queue_3358 <ItemType>::isEmpty() const
{
    return size() == 0;
}

template<class ItemType>
bool Queue_3358 <ItemType>::isFull() const
{
    return (size() + 1) == maxQue;
}

template<class ItemType>
void Queue_3358 <ItemType>::enQueue(const ItemType& newItem)
{
    if(!isFull()) {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
    }
}

template<class ItemType>
ItemType Queue_3358 <ItemType>::deQueue()
{
    assert(!isEmpty());

    ItemType value;

    if (!isEmpty()) {
        value = items[front];
        front = (front + 1) % maxQue;
    }

    return value;
}

#endif
