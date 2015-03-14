#include <iostream>
#include "stack_3358.h"

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

  cout << myStack.pop() << endl;

  cout << "is full?" << myStack.isFull() << endl;

  cout << "is the stack empty? " << myStack.isEmpty() << endl;

  Stack_3358<char> charStack;
  charStack.push('a');
  char popped = charStack.pop();
  cout << "popped: " << popped << endl;
  popped = charStack.pop();
  cout << "popped: " << popped << endl;
  cout << "bool test:" << isalpha(popped) << endl;
}
