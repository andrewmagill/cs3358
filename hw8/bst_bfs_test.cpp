#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "bst_3358.h"

using namespace std;

int getValue(string str) {
    int open = str.find( "(" );
    if( open == std::string::npos )
        return 0;

    int close = str.find( ")" );
    if( open == std::string::npos )
        return 0;

    string strInt = str.substr ( open + 1, close - open - 1 );
    int value = atoi ( strInt.c_str () );

    return value;
}

int main(int argc, char * argv[]) {

    if(argc < 2) {
        cout << "Please provide the name of file containing test input as a parameter.\n";
        return 0;
    }

    ifstream inFile;

    try {
        inFile.open(argv[1]);
    } catch (ifstream::failure e) {
        cerr << "Could not open file\n";
    }

    string str;

    if ( inFile.is_open () ) {
        cout << "\n\t**********************************" << endl;
        cout << "\tTesting the Binary Search Tree and" << endl;
        cout << "\tBreadth First Search algorithm\n" << endl;
        cout << "\tTest File: " << argv[1] << "\n" << endl;

        BST_3358<int> bst;

        while ( getline ( inFile,str ) ) {

            if ( str.find( "insert" ) != std::string::npos ) {

                int value = getValue(str);
                cout << "\tInserting: \t" << value << endl;
                bst.insertItem(value);

            } else if ( str.find( "delete" ) != std::string::npos ) {

                int value = getValue(str);
                cout << "\tDeleting: \t" << value << endl;
                bst.deleteItem(value);

            } else if ( str.find( "find" ) != std::string::npos ) {

                int value = getValue(str);
                cout << "\n\tSearching for: \t" << value << endl;

                string found;
                if(bst.breadthFirstSearch(value))
                    found = "Yes";
                else
                    found = "No";

                cout << "\tFound \t = \t" << found << "\n" << endl;

            } else if ( str.find( "isempty" ) != std::string::npos ) {

                string value;
                if(bst.isEmpty())
                    value = "Yes";
                else
                    value = "No";

                cout << "\n\tIs BST empty? \t" << value << "\n" << endl;

            } else if ( str.find( "isfull" ) != std::string::npos ) {

                string value;
                if(bst.isFull())
                    value = "Yes";
                else
                    value = "No";

                cout << "\n\tIs BST full?: \t\n" << value << "\n" << endl;

            } else if ( str.find( "inorder" ) != std::string::npos ) {

                int value = getValue(str);
                cout << "\n\tIn-Order Traversal: \t\n" << endl;
                bst.inOrderTraversal();
            }
        }
        inFile.close ();

        cout << "\n\tTest Complete" << endl;
        cout << "\n\t**********************************" << endl;
    }
    else {
        cout << "Error: File Not Found.  Exiting." << endl;
    }

    return 0;
}
