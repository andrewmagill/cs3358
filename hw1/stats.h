/* stats.h

Written by Roger Priebe and (Andrew Magill)
1/10/08

This class will provide some simple statistics functions.

//USE THIS FILE FOR DOCUMENTATION (INCLUDING PRE and POST CONDITIONS)

*/

#ifndef STATS_H
#define STATS_H

using namespace std;


class Stats {
    
   static const int MAX_SIZE = 10000;
   private:     
      int numVars;
      double vars[MAX_SIZE];
      
   public:     
      Stats();
      
      void clearData() {
         numVars = 0;
      }
      
      //This function adds one variable to the array in the class.
      //The function returns false if the variable is not successfully added to the class.
      //pre: numVars < MAX_SIZE
      //post: numVars = numvars + 1 and var has been added to the class   
      bool addVar(double var);
      
      //description:  This function displays highest and lowest observed values,
      //              and the calculated mean average and standard deviation.
      //pre:  numVars > 0, vars not empty
      //post: no side affects
      void showData();
  
      //description:  This function calculates the average values contained in the vars array
      //pre:  numVars > 0, vars not empty
      //post: returns the mean average value, a double (no side affects)
      double getAverage();
  
      //description:  This function finds the largest value contained in the vars array
      //pre:  vars is not empty
      //post: returns the highest value in vars, a double (no side affects)
      double findHighest();
  
      //description:  This function finds the smallest value contained in the vars array
      //pre:  vars is not empty
      //post: returns the lowest value in vars, a double (no side affects)
      double findLowest();
  
      //description:  This function calculates the stadard deviation of the values in the vars array
      //              (stddeviation = sqrt of variance, variance = sum(observed[n] - mean average)/count)
      //pre:  numVars > 0, vars not empty
      //post: returns the standard deviation, a double (no side affects)
      double calcStdDeviation();
  
  
      int getNumVars() {
         return numVars;
      }
      
      static int getMaxSize() {
         return MAX_SIZE;
      }    
};

#endif
