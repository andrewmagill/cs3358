/* mathStuff_a_m730.cpp

Roger Priebe and Andrew Magill
cs1428 10/15/07 (updated 04/02/15)

CS 3358 Section 152
Spring 2015
HW 5 Part 1
Recursion - Math Stuff
*/

#include <iostream>
#include <fstream>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);


//******************  MAIN  *****************************

int main () {


    int testNum;

    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;

    if (isPrime(testNum ))
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;

    //test for printing primes
    cout << "Enter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    cout << endl;

    printPrimes(testNum);

    cout << endl;

    //test for Fibonacci number finder
    cout << "Which Fibonacci number? ";
    cin >> testNum;
    cout << endl;

    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;

    cout << endl;

    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;

    findFactors(testNum);

    system("PAUSE");

    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
   const int START_DIVISOR = 2; //HINT: You may want a helper function

   //YOUR CODE GOES HERE

}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n) {

   //YOUR CODE GOES HERE

}



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {

   //YOUR CODE GOES HERE

}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function

   //YOUR CODE GOES HERE

}
