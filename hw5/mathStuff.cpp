/* mathStuff_a_m730.cpp

Roger Priebe and Andrew Magill
cs1428 10/15/07 (updated 04/02/15)

CS 3358 Section 152
Spring 2015
HW 5 Part 1
Inefficient Math with Recursion
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameters - required: positive integer,
//                   optional: positive integer
//returns true if the number is prime, otherwise false
//
// isPrime(n) will call isPrime(n, floor(sqrt(n)), which
// will then call itself recursively, decrementing the
// value of the divisor by 1 on each call until divisor == 1
//
// alternatively, you could create two definitions of isPrimt,
// the first with one parameter, the second with two parameters:
// isPrime(int number) and isPrime(int number, int divisor),
// where isPrime(int number) is really a helper function that calls
// isPrime(int number, int divisor) with divisor = floor(sqrt(number))
// this would be a nice solution if you were creating methods within
// a class, and wanted to hide the two parameter method from the user
bool isPrime (int number, int divisor = 0);

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

    if (isPrime(testNum))
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;

/*
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
*/
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number, int divisor) {

    // a prime number is by definition greater than 1
    if( number <= 1)
        return false;

    double squareRoot = sqrt(number);
    int closeToSquareRoot = floor(squareRoot);

    // let's not divide by zero, this was probably the
    // default parameter, let's start at the top
    if( divisor == 0 )
        return isPrime(number, closeToSquareRoot);

    // if we get to this point, the number is prime
    if( divisor <= 1 )
        return true;

    // don't need to check divisors greater than sqrt(number)
    if( divisor > squareRoot )
        return isPrime(number, closeToSquareRoot);

    // check for divisibility
    int remainder = (number % divisor);

    if(remainder == 0)
        return false;
    else
        return isPrime(number, (divisor-1));

    // if we get here we've done something wrong, we probably
    // should throw an error, but let's return false
    return false;
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
