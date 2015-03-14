#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Stack_3358.h"

using namespace std;

static const int OFFSET_X = 1;
static const int OFFSET_Y = 1;

struct Coord {
   int x;
   int y;

   Coord(int x=0, int y=0)
    : x(x), y(y) {

    }

    Coord& operator=(const Coord& src) {
      x = src.x;
      y = src.y;
      return *this;
    }

    Coord operator+(const Coord& src) const {
      return Coord(src.x+x, src.y+y);
    }

    bool operator==(const Coord& src) const {
      return (x == src.x && y == src.y);
    }
};

enum Direction { NORTH, SOUTH, EAST, WEST };

void travel(vector<string> & box,
  vector<vector<bool> > &visited,
  Stack_3358<Coord> pixelStack,
  Direction direction, Coord start,
  char target, char fill) {

 Coord diff;

  switch(direction) {
    case NORTH :
      cout << "NORTH" << endl;
      diff = Coord(0,-1);
      break;
    case SOUTH :
      cout << "SOUTH" << endl;
      diff = Coord(0,+1);
      break;
    case EAST :
      cout << "EAST" << endl;
      diff = Coord(+1,0);
      break;
    case WEST :
      cout << "WEST" << endl;
      diff = Coord(-1,0);
      break;
  }

  while(box[start.y][start.x] == target) {
    if(!visited[start.y][start.x])
      pixelStack.push(start);
    visited[start.y][start.x] = true;
    start = start + diff;
  }
}

void showPicture(vector<string> & box) {
  string line;

  for(int i = OFFSET_Y; i<box.size()-OFFSET_Y;i++){
    line = box[i];
    for(int j = OFFSET_X; j < line.size()-OFFSET_X; j++)
      cout << line[j];
    cout << "\n";
  }
}

Coord getStartingPosition(int maxHeight, int maxWidth) {
  Coord start;

  while( !((start.y>=1) && (start.y<=maxHeight)) ) {
    cout << "\nEnter a row (1 to "<< maxHeight <<"): ";
    cin >> start.y;
  }

  while( !((start.x>=1) && (start.x<=maxWidth)) ) {
    cout << "Enter a column (1 to " << maxWidth <<"): ";
    cin >> start.x;
  }

  return start;
}

int main (int argc, char * argv[]) {

  if ( argc != 2 ) {
    cerr << "Error: Invalid parameters." << endl;
    cerr << "Please enter a file name to analyze." << endl;
    cerr << "Ex:  $ ./equationChecker eq.dat" << endl;
    return EXIT_FAILURE;
  }

  ifstream inFile ( argv[1] );
  vector<string> box;
  string line;

  int linesize = 0;

  if ( inFile.is_open () ) {
    string border;
    while ( getline ( inFile, line ) ) {
      if(box.size() == 0) {
        linesize = line.size();
        for(int i = 0; i < linesize+2; i++)
          border += '\0';
        box.push_back(border);
      }
      box.push_back('\0' + line + '\0');
    }
    box.push_back(border);
  }

  vector< vector<bool> > visited(box.size(),vector<bool>(linesize+2));

  cout << "\noriginal picture: \n\n";

  showPicture(box);

  int pictureHeight = box.size()-2;
  int pictureWidth = linesize;

  Coord start = getStartingPosition(pictureHeight, pictureWidth);

  char color = '-';

  while(!isalpha(color)) {
    cout << "Enter a color (English letter): ";
    cin >> color;
  }

  char originalColor = box[start.y][start.x];

  if (originalColor == '\0') {
    cerr << "uh oh" << endl;
    return EXIT_FAILURE;
  }


  Stack_3358<Coord> pixelStack;

  //fill(box, visited, pixelStack, start, originalColor, color);

  cout << "\nflood filled picture \n\n";

  showPicture(box);

  return EXIT_SUCCESS;
}
