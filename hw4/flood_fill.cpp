#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Stack_3358.h"

using namespace std;

static const int PICTURE_HEIGHT = 7;
static const int PICTURE_WIDTH = 17;

static const int BOARD_HEIGHT = 9;
static const int BOARD_WIDTH = 19;

static const int OFFSET_X = 1;
static const int OFFSET_Y = 1;

typedef struct coord {
   int x;
   int y;
} Coord;
/*
void generate(char (&board)[BOARD_HEIGHT][BOARD_WIDTH]) {
  for(int y = 0; y<BOARD_HEIGHT; y++) {
    for(int x = 0; x<BOARD_WIDTH; x++) {
      board[y][x] = 'N';
    }
  }
}

void fill(char (&board)[BOARD_HEIGHT][BOARD_WIDTH]) {
  for(int y = OFFSET_Y; y<=PICTURE_HEIGHT; y++) {
    for(int x = OFFSET_X; x<=PICTURE_WIDTH; x++) {
      board[y][x] = 'f';
    }
  }
}

void flood(char (&board)[BOARD_HEIGHT][BOARD_WIDTH]) {
  for(int y = 0; y<BOARD_HEIGHT; y++) {
    for(int x = 0; x<BOARD_WIDTH; x++) {

    }
  }
}

void show(char (&board)[BOARD_HEIGHT][BOARD_WIDTH]) {
  for(int y = 0; y<BOARD_HEIGHT; y++) {
    for(int x = 0; x<BOARD_WIDTH; x++) {
      cout << board[y][x];
    }
    cout << endl;
  }
}
*/
void fill(vector<string> & box, vector<vector<bool> > &visited, Stack_3358<Coord> pixelStack, Coord start, char original, char originalColor) {
  Coord north = start;
  Coord south = start;
  Coord east = start;
  Coord west = start;

  while(box[north.y][north.x] == originalColor) {
    if(visited[north.y][north.x])
      pixelStack.push(north);
    visited[north.y][north.x] = true;
    north.y--;
  }

  while(box[south.y][south.x] == originalColor) {
    if(visited[south.y][south.x])
      pixelStack.push(south);
    visited[south.y][south.x] = true;
    south.y++;
  }

  while(box[east.y][east.x] == originalColor) {
    if(visited[east.y][east.x])
      pixelStack.push(east);
    visited[east.y][east.x] = true;
    east.y--;
  }

  while(box[west.y][west.x] == originalColor) {
    if(visited[west.y][west.x])
      pixelStack.push(west);
    visited[west.y][west.x] = true;
    west.y--;
  }
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

  for(int i = OFFSET_Y; i<box.size()-OFFSET_Y;i++){
    line = box[i];
    for(int j = OFFSET_X; j < line.size()-OFFSET_X; j++)
      cout << line[j];
    cout << "\n";
  }

  int row = -1;
  int column = -1;
  char color = '-';

  while(!((row>=1)&&(row<box.size()-1))) {
    cout << "\nEnter a row (1 to "<< box.size()-2 <<"): ";
    cin >> row;
  }

  while(!((column>=1)&&(column<linesize))) {
    cout << "Enter a column (1 to " << linesize-1 <<"): ";
    cin >> column;
  }

  while(!isalpha(color)) {
    cout << "Enter a color (English letter): ";
    cin >> color;
  }
  Coord start;
  start.x = column;
  start.y = row;

  char originalColor = box[start.y][start.x];

  if (originalColor == '\0') {
    cerr << "uh oh" << endl;
    return EXIT_FAILURE;
  }

  Stack_3358<Coord> pixelStack;

  //fill(box, visited, pixelStack, start, originalColor, color);

/*
  for(int i = OFFSET_Y; i<box.size()-OFFSET_Y;i++){
    line = box[i];
    for(int j = OFFSET_X; j < line.size()-OFFSET_X; j++) {

    }
  }
*/
  cout << "\nflood filled picture \n\n";

  for(int i = OFFSET_Y; i<box.size()-OFFSET_Y;i++){
    line = box[i];
    for(int j = OFFSET_X; j < line.size()-OFFSET_X; j++)
      cout << line[j];
    cout << "\n";
  }

  //char board[BOARD_HEIGHT][BOARD_WIDTH];
  //generate(board);
  //fill(board);
  //show(board);

  return EXIT_SUCCESS;
}
