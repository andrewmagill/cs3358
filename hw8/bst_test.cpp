//BST_test.cpp
//CS3358
//written by Dr. Priebe
//
//tests a BST

#include <iostream>
#include "bst_3358.h"

using namespace std;

int main () {

   BST_3358<int> myBST;

   myBST.insertItem(42);
   myBST.insertItem(12);
   myBST.insertItem(8);
   myBST.insertItem(15);

   cout << "I have " << myBST.countNodes() << " nodes" << endl;
   cout << "int" << endl;
   myBST.inOrderTraversal();
   cout << "pre" << endl;
   myBST.preOrderTraversal();
   cout << "post" << endl;
   myBST.postOrderTraversal();

   myBST.deleteItem(12);

   myBST.inOrderTraversal();

   cout << " delete 12 again " << endl;

   myBST.deleteItem(12);

   cout << " make empty " << endl;

   myBST.makeEmpty();

   if (myBST.isEmpty())
      cout <<" it's empty"<< endl;
   else
      cout << "oops" << endl;

   myBST.inOrderTraversal();
   myBST.insertItem(123);
   myBST.inOrderTraversal();
}
