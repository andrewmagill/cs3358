#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "stack_3358.h"

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
/*
    string toString() {
      std::stringstream ss;
      ss << "hello world" << endl;
      std::string str = ss.str();
      return ss;//"(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }*/
    /*
    ostream& operator << (ostream& os, const Coord& rhs) {
        os << rhs.x << rhs.y;
        return os;
    }*/
};

enum Direction { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };

void travel(vector<string> & box,
  vector<vector<bool> > &visited,
  Stack_3358<Coord> &pixelStack,
  Direction direction, Coord start,
  char target, char fill) {

 Coord diff;

  switch(direction) {
    case NORTH :
      diff = Coord(0,-1);
      break;
    case NORTHEAST :
      diff = Coord(1,-1);
    case EAST :
      diff = Coord(1,0);
      break;
    case SOUTHEAST :
      diff = Coord(1,1);
      break;
    case SOUTH :
      diff = Coord(0,1);
      break;
    case SOUTHWEST :
      diff = Coord(-1,1);
      break;
    case WEST :
      diff = Coord(-1,0);
      break;
    case NORTHWEST :
      diff = Coord(-1,-1);
      break;

  }

  while(box[start.y][start.x] == target) {
    if(!visited[start.y][start.x])
      pixelStack.push(start);
    //visited[start.y][start.x] = true;
    start = start + diff;
    //cout << start.toString() << endl;
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
    if(start.y < 0) {
      cout << "Thank you, program exiting." << endl;
      exit(0);
    }
  }

  while( !((start.x>=1) && (start.x<=maxWidth)) ) {
    cout << "Enter a column (1 to " << maxWidth <<"): ";
    cin >> start.x;
    if(start.x < 0) {
      cout << "Thank you, program exiting." << endl;
      exit(0);
    }
  }

  return start;
}

vector<string> readInFromFile(char* fileName, int &lineNumber) {

  ifstream inFile ( fileName );
  vector<string> box;
  string line;

  int linesize = 0;
  int readlines = 0;
  int processedlines = 0;

  if ( inFile.is_open () ) {
    string border;
    while ( getline ( inFile, line ) ) {
      readlines++;
      if(readlines<=lineNumber) {
        cout << "skipping" << readlines << endl;
        continue;
      }
      if(processedlines>=25)
        break;

      cout << "not skipping " << readlines << endl;

      if(box.size() == 0) {
        linesize = line.size();
        for(int i = 0; i < linesize+2; i++)
          border += '\0';
        box.push_back(border);
      } else if ((!isalpha(line[0])) && (readlines > 1)) {
        break;
      }

      box.push_back('\0' + line + '\0');
      processedlines++;
    }
    box.push_back(border);
  }

  lineNumber += readlines;
  return box;
}

char getFillColor() {
  char color = '-';

  while(!isalpha(color)) {
    cout << "Enter a color (English letter): ";
    cin >> color;
  }

  return color;
}

int main (int argc, char * argv[]) {

  if ( argc != 2 ) {
    cerr << "Error: Invalid parameters." << endl;
    cerr << "Please enter a file name to analyze." << endl;
    cerr << "Ex:  $ ./flood_fill fake_picture.txt" << endl;
    return EXIT_FAILURE;
  }

  int lineNumber = 0;

  for(int r = 0; r < 25; r++) {

    vector<string> box = readInFromFile(argv[1], lineNumber);

    vector< vector<bool> > visited(box.size(),vector<bool>(box[0].size()));

    cout << "\noriginal picture: \n\n";

    showPicture(box);

    int pictureHeight = box.size()-2;
    int pictureWidth = box[0].size()-2;

    Coord start = getStartingPosition(pictureHeight, pictureWidth);

    char fillColor = getFillColor();

    char targetColor = box[start.y][start.x];

    if (targetColor == '\0') {
      cerr << "Starting position is out of bounds." << endl;
      return EXIT_FAILURE;
    }

    Stack_3358<Coord> pixelStack;
    pixelStack.push(start);

    while(!pixelStack.isEmpty()) {
      Coord pos = pixelStack.pop();
      visited[pos.y][pos.x] = true;
      //cout << pos.toString() << endl;

      travel(box, visited, pixelStack, NORTH, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, NORTHEAST, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, EAST, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, SOUTHEAST, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, SOUTH, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, SOUTHWEST, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, WEST, pos, targetColor, fillColor);
      travel(box, visited, pixelStack, NORTHWEST, pos, targetColor, fillColor);

      box[pos.y][pos.x] = fillColor;
    }

    cout << "\nflood filled picture \n\n";

    showPicture(box);

    cout << "\n--------------\n" << endl;
  }

  return EXIT_SUCCESS;
}
