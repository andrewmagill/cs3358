#ifndef MYTEMPLATEDLIST_H
#define MYTEMPLATEDLIST_H

#include <vector>

using namespace std;

// header

namespace cs3358_LL {
  template <class T>
  class List_3358 {
    public:

      typedef int value_type;
      typedef size_t size_type;

      // constructors

      List_3358 ( );
      List_3358 ( const List_3358 & src );
      ~List_3358 ( );

      // mutators

      void insert ( const T & item );
      void remove ( );
      void reset ( );
      bool advance ( );

      // accessors

      bool isEmpty ( ) const;
      bool atEOL ( ) const;
      T getCurrent ( ) const;

    private:

      struct Node {
        T value;
        Node* next;
        Node* previous;
      };

      Node* head;
      Node* tail;
      Node* cursor;
  };
}

// implementation

namespace cs3358_LL {

  // constructors

  template <class T>
  List_3358<T>::List_3358() {
    cout<<"Constructor, allocate..."<<endl;

    head = NULL;
  	tail = NULL;
  	cursor = NULL;
  }

  template <class T>
  List_3358<T>::List_3358 (const List_3358 & src) {
    cout<<"Copy constructor, allocate..."<<endl;

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

  template <class T>
  List_3358<T>::~List_3358() {
    cout<<"Constructor, deallocate..."<<endl;

    // fun part
  	Node *p = head;

  	while (head != NULL) {
  	  head = head->next;
  		delete p;
  		p = head;
  	}
  }

  // mutators

  template <class T>
  void List_3358<T>::insert ( const T & item ) {
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

  template <class T>
  void List_3358<T>::remove ( ) {
  	// do nothing if list is empty
  	//if (atEOL() || isEmpty())
    if (isEmpty())
  	  return;

    // alright, if the cursor is after the tail, i say you delete the tail
    bool eol = atEOL();
    if (eol)
      cursor = tail;

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

    if (eol)
      cursor = NULL;
  }

  template <class T>
  void List_3358<T>::reset ( ) {
  	cursor = head;
  }

  template <class T>
  bool List_3358<T>::advance ( ) {
  	if(!atEOL())
  	  cursor = cursor->next;

  	return (!atEOL());
  }

  // accessors

  template <class T>
  bool List_3358<T>::isEmpty ( ) const {
  	return (head == NULL);
  }

  template <class T>
  bool List_3358<T>::atEOL ( ) const {
  	return (cursor==NULL);
  }

  template <class T>
  T List_3358<T>::getCurrent ( ) const {
  	if (!atEOL())
  	  return cursor->value;
  }
}

#endif
