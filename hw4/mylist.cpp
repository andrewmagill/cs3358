#include "mylist.h"

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
	return NULL;
}
