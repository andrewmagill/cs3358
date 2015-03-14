#include <iostream>
#include "Stack_3358.h"

using namespace std;

int main() {
  Stack_3358<int> myStack;
  Stack_3358<int> myOtherStack = myStack;

  if(!myStack.isEmpty())
    cout << "pop: " << myStack.pop() << endl;

  myStack.push(54);

  if(!myStack.isEmpty())
    cout << "pop: " << myStack.pop() << endl;

  myStack.push(324);
  myStack.push(67);

  myStack.makeEmpty();

  cout << "is full?" << myStack.isFull();

  cout << "is the stack empty? " << myStack.isEmpty() << endl;
}
