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

    cout << "myBST.insertItem(42);\n" << endl;
    myBST.insertItem(42);

    cout << "myBST.insertItem(12);\n" << endl;
    myBST.insertItem(12);

    cout << "myBST.insertItem(8);\n" << endl;
    myBST.insertItem(8);

    cout << "myBST.insertItem(15);\n" << endl;
    myBST.insertItem(15);

    cout << "I have " << myBST.countNodes() << " nodes" << endl;

    cout << "in order traversal:\n" << endl;
    myBST.inOrderTraversal();

    cout << "pre order traversal:\n" << endl;
    myBST.preOrderTraversal();

    cout << "post order traversal:\n" << endl;
    myBST.postOrderTraversal();

    cout << "myBST.deleteItem(12);\n" << endl;
    myBST.deleteItem(12);

    cout << "in order traversal:\n" << endl;
    myBST.inOrderTraversal();

    cout << "delete 12 again\n " << endl;
    myBST.deleteItem(12);

    cout << "in order traversal:\n" << endl;
    myBST.inOrderTraversal();

    cout << "make empty\n" << endl;
    myBST.makeEmpty();

    if (myBST.isEmpty())
      cout <<"it's empty\n"<< endl;
    else
      cout << "oops\n" << endl;

    cout << "in order traversal:\n" << endl;
    myBST.inOrderTraversal();

    cout << "myBST.insertItem(123);\n" << endl;
    myBST.insertItem(123);

    cout << "in order traversal:\n" << endl;
    myBST.inOrderTraversal();

    cout << "\nmyBST.breadthFirstSearch(123); " << myBST.breadthFirstSearch(123) << endl;

    return 0;
}
