#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "stack_3358.h"

using namespace std;

static const string OPENING_CHARS = "([{<";
static const string CLOSING_CHARS = ")]}>";

string makeTabs(string & equation) {
  string tabs = "\t\t";
  if(equation.length() > 12)
    tabs = "\t";
  else if(equation.length() > 16)
    tabs = "";

  return tabs;
}

int groupingMatch(string & equation) {
  int openCount = 0;
  int closingCount = 0;

  for(std::string::size_type i = 0; i < equation.size(); ++i) {
    char character = equation[i];

    if ( OPENING_CHARS.find( character ) != std::string::npos ) {
      openCount++;
    } else if ( CLOSING_CHARS.find( character ) != std::string::npos ) {
      closingCount++;
    }
  }

  return openCount - closingCount;
}

bool symbolMatch(string & equation) {
  Stack_3358<char> groupingCharStack;
  string tabs = makeTabs(equation);

  for(std::string::size_type i = 0; i < equation.size(); ++i) {
    char character = equation[i];

    if ( OPENING_CHARS.find( character ) != std::string::npos ) {

      groupingCharStack.push( character );

    } else if ( CLOSING_CHARS.find( character ) != std::string::npos ) {

      int closingSymbolIndex = CLOSING_CHARS.find( character );
      char poppedSymbol = groupingCharStack.pop();
      int openingSymbolIndex = OPENING_CHARS.find( poppedSymbol );

      if (closingSymbolIndex != openingSymbolIndex) {
        cout << "The equation:\t" << equation << tabs <<"is not formed correctly.  ";
        cout << "The symbols: " << poppedSymbol << ", and " << character << " do not match!" << endl;
        return false;
      }
    }
  }

  return true;
}

int main (int argc, char * argv[]) {

  if ( argc != 2 ) {
    cerr << "Error: Invalid parameters." << endl;
    cerr << "Please enter a file name to analyze." << endl;
    cerr << "Ex:  $ ./equationChecker eq.dat" << endl;
    return EXIT_FAILURE;
  }

  ifstream inFile ( argv[1] );
  string equationString;
  Stack_3358<char> groupingCharStack;

  if ( inFile.is_open () ) {
    while ( getline ( inFile, equationString ) ) {

      string tabs = makeTabs(equationString);

      int count = groupingMatch(equationString);
      if(count > 0) {
        cout << "The equation:\t" << equationString << tabs << "is not formed correctly, ";
        cout << "there are too many opening symbols. " << endl;
      } else if(count < 0) {
        cout << "The equation:\t" << equationString << tabs << "is not formed correctly, ";
        cout << "there are too many closing symbols. " << endl;
      } else {
        if(symbolMatch(equationString)) {
          cout << "The equation:\t" << equationString << tabs << "is formed correctly!" << endl;
        }
      }

      groupingCharStack.makeEmpty();
    }
  } else {
    cerr << "Error opening file" << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
