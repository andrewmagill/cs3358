#include <iostream>
#include <fstream>

using namespace std;

const int PICTURE_SIZE = 27;
const int BORDER_SIZE = 1;
const char NULL_CHAR = 'X';

void showPicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE]);

void initializePicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE]);

void initializeVisited(bool (&visited)[PICTURE_SIZE][PICTURE_SIZE]);

void getPicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE], char * fileName);

void floodFill(char (&pic)[PICTURE_SIZE][PICTURE_SIZE],
                    bool (&visited)[PICTURE_SIZE][PICTURE_SIZE],
                    int row, int column, char newColor, char oldColor);

int main (int argc, char * argv[]) {

    if ( argc != 2 ) {
      cerr << "Error: Invalid parameters." << endl;
      cerr << "Please enter a file name to analyze." << endl;
      cerr << "Ex:  $ ./flood_fill2 fake_picture.txt" << endl;
      return EXIT_FAILURE;
    }

    char picture [PICTURE_SIZE][PICTURE_SIZE];
    bool visited [PICTURE_SIZE][PICTURE_SIZE];

    initializePicture(picture);
    getPicture(picture, argv[1]);

    int startRow = 0;
    int startColumn = 0;
    char newColor = 'Z';
    char oldColor = 'Z';

    // user input loop
    while(true) {

        // we need to reset this each time
        initializeVisited(visited);

        cout << endl;
        showPicture(picture);
        cout << endl;

        cout << "Enter a row: ";
        cin >> startRow;
        if(startRow < 0) {
          cout << "Thank you, program exiting." << endl;
          exit(0);
        }

        cout << "Enter a column: ";
        cin >> startColumn;
        if(startColumn < 0) {
          cout << "Thank you, program exiting." << endl;
          exit(0);
        }

        cout << "Enter a color: ";
        cin >> newColor;

        cout << "row: " << startRow << ", column: "<< startColumn << endl;
        oldColor = picture[startRow][startColumn];

        cout << "\nnew color: " << newColor;
        cout << ", old color: " << oldColor << endl;

        if(oldColor != NULL_CHAR)
            floodFill(picture, visited, startRow, startColumn, newColor, oldColor);
    }

    return 0;
}

void floodFill(char (&pic)[PICTURE_SIZE][PICTURE_SIZE],
                    bool (&visited)[PICTURE_SIZE][PICTURE_SIZE],
                    int row, int column, char newColor, char oldColor) {
    visited[row][column] = true;
    if(pic[row][column] == oldColor) {
        // this is a little messy
        if(!visited[row-1][column])
            floodFill(pic, visited, (row-1), column, newColor, oldColor); //NORTH
        if(!visited[row-1][column+1])
            floodFill(pic, visited, (row-1), (column+1), newColor, oldColor); //NORTHEAST
        if(!visited[row][column+1])
            floodFill(pic, visited, row, (column+1), newColor, oldColor); //EAST
        if(!visited[row+1][column+1])
            floodFill(pic, visited, (row+1), (column+1), newColor, oldColor); //SOUTHEAST
        if(!visited[row+1][column])
            floodFill(pic, visited, (row+1), column, newColor, oldColor); //SOUTH
        if(!visited[row+1][column-1])
            floodFill(pic, visited, (row+1), (column-1), newColor, oldColor); //SOUTHWEST
        if(!visited[row][column-1])
            floodFill(pic, visited, row, (column-1), newColor, oldColor); //WEST
        if(!visited[row-1][column-1])
            floodFill(pic, visited, (row-1), (column-1), newColor, oldColor); //NORTHWEST
        pic[row][column] = newColor;
    }
    return;
}

void getPicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE], char * fileName) {
    fstream fin(fileName, fstream::in);
    char character;
    int rowCount = BORDER_SIZE;
    int columnCount = BORDER_SIZE;

    while(fin >> noskipws >> character) {
        if(columnCount > (PICTURE_SIZE-(2*BORDER_SIZE)))
            continue;
        if(rowCount > (PICTURE_SIZE-(2*BORDER_SIZE)))
            break;

        if(character == '\n') {
            columnCount = BORDER_SIZE;
            rowCount++;
        } else {
            pic[rowCount][columnCount] = character;
            columnCount++;
        }
    }
}

void initializeVisited(bool (&visited)[PICTURE_SIZE][PICTURE_SIZE]) {
    for(int row = 0; row < PICTURE_SIZE; row++) {
        for(int column = 0; column < PICTURE_SIZE; column++) {
            visited[row][column] = false;
        }
    }
}

void initializePicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE]) {
    for(int row = 0; row < PICTURE_SIZE; row++) {
        for(int column = 0; column < PICTURE_SIZE; column++) {
            pic[row][column] = NULL_CHAR;
        }
    }
}

void showPicture(char (&pic)[PICTURE_SIZE][PICTURE_SIZE]) {
    for(int row = 0; row < PICTURE_SIZE; row++) {

        //if(pic[row][BORDER_SIZE] != NULL_CHAR)
        //    cout << row << " ";

        for(int column = 0; column < PICTURE_SIZE; column++) {
            char character = pic[row][column];

            if(character != NULL_CHAR)
                cout << character;
        }

        if(pic[row][BORDER_SIZE] != NULL_CHAR)
            cout << endl;
    }
}
