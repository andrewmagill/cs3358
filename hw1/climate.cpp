/* climate.cpp
 * Andrew Magill - a_m730
 * CS 33358 Section 251
 * Program 01
 * Input:   Program takes the name of a text file as input;
 *          ex: $ ./analyze climate_data.txt,
 *          Where climate_data.txt represents monthly 
 *          CO2 levels measured by the NOAA.
 * Purpose: The program outputs the highest, lowest, 
 *          average, and standard deviation, or the 
 *          given CO2 levels.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main (int argc, char * argv[]) {
    if ( argc != 2 ) {
        cout << "Error: Invalid parameters." << endl;
        cout << "Please enter a file name to analyze." << endl;
        cout << "Ex:  $ ./analyze climate_data.txt" << endl;
        return 0;
    }

    string str;
    ifstream inFile ( argv[1] );

    string strDouble;
    int intCount = 0;  
    double dblCurrent = 0;
  
    vector<double> co2Readings;
  
    double dblLow = 0;
    double dblHigh = 0;
    double dblTotal = 0;
    double dblMeanAvg = 0;
    double dblVariance = 0;
    double dblStdDeviation = 0;

    if ( inFile.is_open () ) {
      while ( getline ( inFile,str ) ) {
        if ( str.find( "MLO" ) != std::string::npos ) {
            strDouble = str.substr ( str.length () - 7, 7 );
            dblCurrent = atof ( strDouble.c_str () );
          
            if ( ( dblLow == 0 ) or ( dblCurrent < dblLow ) ) {
              dblLow = dblCurrent;
            }
          
            if ( dblCurrent > dblHigh ) {
              dblHigh = dblCurrent;
            }         
          
            co2Readings.push_back ( dblCurrent );
            dblTotal += dblCurrent;
            intCount++;
        }
      }
        inFile.close ();
    }
    else {
        cout << "Error: File Not Found.  Exiting." << endl;
    }
  
    dblMeanAvg = dblTotal / intCount;
  
    for ( int i = 0; i < co2Readings.size (); i++) {
      dblVariance += pow( ( co2Readings[i] - dblMeanAvg ), 2 );
    }
    
    dblVariance = dblVariance / intCount;
    dblStdDeviation = sqrt(dblVariance);
  
    cout << " ===== Results ===== " << endl;
    cout << " Records Processed: " << intCount << endl;
    cout << " Lowest CO2: " << dblLow << endl;
    cout << " Highest CO2: " << dblHigh << endl;
    cout << " Average CO2: " << dblMeanAvg << endl;
    cout << " Standard Deviation: " << dblStdDeviation << endl;

    return 0;
}