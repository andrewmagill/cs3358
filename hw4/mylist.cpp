#include "mylist.h"
#include <iostream>

using namespace std;
using namespace cs3358;

// constructors

MyList::MyList () {
  head = NULL;
	tail = NULL;
	cursor = NULL;
}

MyList::MyList (const MyList & src) {
	// cases:
	// 1) src is empty
	// 2) src is not empty

	if (src.head == NULL) {
		// like the default constructor
		head = NULL;
		tail = NULL;
		cursor = NULL;
	} else {
		// we will need these
		Node *temp;
		Node *prev = NULL;

		// move through the list until next is NULL
		for (Node *p = src.head; p != NULL; p=p->next) {
			temp = new Node;
			temp->value = p->value;
			temp->next = NULL;

			// the first time we run through this we want to point
			// prev to temp, on subsequent iterations, point prev->next to temp,
			// then prev to temp
			if (prev == NULL) {
				prev = temp;
			} else {
				// attaching out new node to the list
				prev->next = temp;
				prev = temp;
			}

			// fix up the head, tail, cursor
			if ( p == src.head )
			  head = temp;
			if ( p == src.cursor )
			  cursor = temp;
			if ( p == src.tail )
			  tail = temp;
		}
	}
}

MyList::~MyList () {
	// fun part
	Node *p = head;

	while (head != NULL) {
	  head = head->next;
		delete p;
		p = head;
	}
}

// mutators

void MyList::insert ( const value_type & item ) {
	// not implementing isFull, not going to check for that
	Node *temp = new Node;
	temp->value = item;
	temp->next = NULL;
	temp->previous = NULL;

	// four cases:
	// 1) list is empty
	// 2) cursor is at EOL
	// 3) cursor is at head
	// 4) cursor is in the middle

	if (isEmpty()) { // case 1
		// point head and tail = temp
		head = temp;
		tail = temp;
	} else if (atEOL()) { // case 2
		// make temp the new tail:
		// * point (current) tail->next to temp
    // * point temp->previous to tail
		// * point tail to temp
		tail->next = temp;
		temp->previous = tail;
		tail = temp;
	} else { // might be case 3 or 4
		if (cursor == head) { // case 3
			// make temp the new head:
			// * point temp->next to (current) head
			// * point head->previous to temp
      // * point head to temp
			temp->next = head;
      head->previous = temp;
			head = temp;
		} else { // case 4
      // stick temp between nodes - note that order matters
      // * point temp->next to the cursor, because we're sticking this behind the cursor
      // * point temp->previous to cursor->previous
      // * ok now point that previous node's next to temp
      // * and finally point cursor->previous to temp
      temp->next = cursor;
      temp->previous = cursor->previous;
      temp->previous->next = temp;
      cursor->previous = temp;
		}
	}
}

void MyList::remove ( ) {
	// do nothing if list is empty
	if (atEOL() && isEmpty()) // not sure why isEmpty() isn't sufficient
	  return;

  // conditional fall through:
  // * cursor is pointing to the head
  //   * and cursor is also pointing to the tail
  // * cursor is pointing to the tail
  // * cursor is pointing to a node in the middle

  if (cursor == head) {
    if (cursor == tail) {
      delete cursor;
      cursor = NULL;
      head = NULL;
      tail = NULL;
    } else {
      head = head->next;
      head->previous = NULL;
      delete cursor;
      cursor = head;
    }
  } else if (cursor == tail) {
    tail = tail->previous;
    tail->next = NULL;
    delete cursor;
    cursor = tail;
  } else {
    Node *nextNode = cursor->next;
    Node *previousNode = cursor->previous;

    nextNode->previous = previousNode;
    previousNode->next = nextNode;
    delete cursor;
    cursor = nextNode;
  }
}

void MyList::reset ( ) {
	cursor = head;
}

bool MyList::advance ( ) {
	if(!atEOL())
	  cursor = cursor->next;

	return (!atEOL());
}

// accessors

bool MyList::isEmpty ( ) const {
	return (head == NULL);
}

bool MyList::atEOL ( ) const {
	return (cursor==NULL);
}

MyList::value_type MyList::getCurrent ( ) const {
	if (!atEOL())
	  return cursor->value;
}
