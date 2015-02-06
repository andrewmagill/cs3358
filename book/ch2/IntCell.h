// Data Structures and Problem Solving Using C++ (2nd Edition) by Mark A. Weiss
// A class for simulating an integer memory cell.

Class IntCell
{
  public:
  
      // Construct the IntCell.  Initial value is initialValue.
      // Use explicit to avoid unwanted type conversion (since this 
      // is a one parameter constructor).
    explicit IntCell( int initialValue = 0 )
      : storedValue( initialValue ) { }
  
      // Return the stored value.
    int read( )
      { return storedValue; }
  
      // Change the stored value to x.
    void write( int x )
      { storedValue = x; }
  
  private:
    int storedValue;
}