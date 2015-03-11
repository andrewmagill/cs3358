#ifndef MYLIST_H
#define MYLIST_H

#include <cstdlib>

using namespace std;

namespace cs3358 {
  class MyList {
    public:

      typedef int value_type;
      typedef size_t size_type;

      MyList ( );

      MyList ( const MyList & src );

      ~MyList ( );

    private:

      struct Node {
        value_type value;
        Node* next;
        Node* previous;
      };

      Node* head;
      Node* tail;
      Node* cursor;
  };
}

#endif
