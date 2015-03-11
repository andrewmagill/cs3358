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
		// * point tail to temp
		tail->next = temp;
		tail = temp;
	} else { // might be case 3 or 4
		if (cursor == head) { // case 3
			// make temp the new head:
			// * point temp->next to (current) head
			// * point head to temp
			temp->next = head;
			head = temp;
		} else { // case 4
      // stick temp in the middle
			// * we will need a temporary pointer, we'll call it p
			// * point p to head
			// * then we need to walk p down to the node before the cursor
			//   (while not p-> == cursor, p = p->next // so that p is the node before the cursor)
			//   (if we implement previous we would just point it to cursor->previous)
			// * point p->next to temp
			// * point temp->next to cursor
			//   (so that you are inserting in front of the cursor)
			Node *p = head;
			while (p->next != cursor)
			  p = p->next;

			p->next = temp; // connects lhs to new node (temp)
			temp->next = cursor; // connect new node (temp) to rhs
		}
	}
}

void MyList::remove ( ) {
	// do nothing if list is empty
	cout << "	*	*	*\tremove - beginning\t\t*	*	*" << endl;
	if (atEOL() && isEmpty()) // not sure why isEmpty() isn't sufficient
	  return;

		cout << "	*	*	*\tremove - after first return\t*	*	*" << endl;
	// three cases (non-empty list):
	// 1) the cursor is at the head
	// 2) the cursor is at the tail
	// 3) the cursor is in the middle

	Node *p = head; // we're going to need this

	if (cursor == head) { // case 1
		cout << "	*	*	*\tremove - case 1\t\t*	*	*" << endl;

		// Note: p points to head at this point
		// * point head to head->next
		// * delete node pointed to by p (former head)
		// * point the cursor to the new head
		// * if head is null (because we deleted the only item in the list)
		//   then we need to set tail == NULL, because we deleted the node it was pointing to

		head = head->next;
		delete p;
		cursor = head;

		if (head == NULL)
		  tail = NULL;
	} else { // case 2 or case 3
		cout << "	*	*	*\tremove - case 2/3\t\t*	*	*" << endl;

		// * point p to node before the cursor
		// * point p->next to the node after the cursor

      while (p->next != cursor)
		    p = p->next;

			p->next = cursor->next;

		if (cursor == tail) { // case 2
			cout << "	*	*	*\tremove - case 2\t\t*	*	*" << endl;
			// * delete the node pointed to by the cursor
			// * point the tail to p;
			// ! I think p->next should be NULL
			// * set the cursor = NULL (EOL)

      delete cursor;
			p->next = NULL;
			tail = p;
			cursor = NULL;
		}	else { // case 3
			cout << "	*	*	*\tremove\t-\tcase 3\t*	*	*" << endl;
			// * delete the node pointed to by the cursor
			// * point the cursor to the node that was after the cursor (before we deleted it)

		}
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
