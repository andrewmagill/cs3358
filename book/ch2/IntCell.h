#ifndef _IntCell_H_
#define _IntCell_H_

// Data Structures and Problem Solving Using C++ (2nd Edition) by Mark A. Weiss
// A class for simulating an integer memory cell.

Class IntCell
{
  public:
    // Construct the IntCell.  Initial value is initialValue.
    // Use explicit to avoid unwanted type conversion (since this 
    // is a one parameter constructor).
    explicit IntCell( int initialValue = 0 )
    // Return the stored value.
    int read( ) const;  
    // Change the stored value to x.
    void write( int x );
  
  private:
    int storedValue;
};

#endif