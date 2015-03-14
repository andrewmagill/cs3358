#include <iostream>
#include "Stack_3358.h"

using namespace std;

int main() {
  Stack_3358<int> myStack;
  Stack_3358<int> myOtherStack = myStack;
  cout << myStack.isEmpty() << endl;
}
