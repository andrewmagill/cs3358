/* mathStuff_a_m730.cpp

Roger Priebe and Andrew Magill
cs1428 10/15/07 (updated 04/02/15)

CS 3358 Section 152
Spring 2015
HW 5 Part 1
Math with Recursion
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameters - required: 'number', a positive integer,
//                   optional: 'divisor', a positive integer
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
//input parameters - required: 'number', a positive integer,
//                   optional: 'divisor', a positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number, int divisor = 0);

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

    //test for printing primes
    cout << "\nEnter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    if(testNum < 2)
        cout << endl << testNum << " is too small.";
    else
        cout << endl << "Prime Numbers between 1 and " << testNum << ":\n\n";

    printPrimes(testNum);

    cout << endl;

    //test for Fibonacci number finder
    cout << "\nWhich Fibonacci number? ";
    cin >> testNum;
    cout << endl;

    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;

    cout << endl;

    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;

    if(testNum > 1) {
        cout << endl << "Prime factorization of " << testNum << ": ";
        findFactors(testNum);
    } else {
        cout << endl << testNum << " is too small\n\n";
    }

    return 0;
}

//function isPrime
//input parameters - required: 'number', a positive integer,
//                   optional: 'divisor', a positive integer
//returns true if the number is prime, otherwise false

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
    if(n < 2)
        return;

    printPrimes(n-1);

    // we're starting at n and decrementing, but we want
    // to list prime in ascending order, so we'll print out
    // after the recursion
    if(isPrime(n))
        cout << n << " ";
}

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
//n max around 45 for this implementation

int findFibo (int n) {

    if( n == 0 )
        return 0;

    if( n == 1 )
        return 1;

    return findFibo(n-2) + findFibo(n-1);
}


//function findFactors
//input parameters - required: 'number', a positive integer,
//                   optional: 'divisor', a positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number, int divisor) {

    const int START_DIVISOR = 2; //HINT: You may want a helper function

    // 2 is the smallest prime, this is stopping condition
    if( number <= 1 ) {
        // this is a little hack to remove last '*'
        cout << "\b " << endl;
        return;
    }

    // if the divisor is larger than the numberator, there's no point
    // in going any further, this is a stopping condition
    if( divisor > number ) {
        // this is a little hack to remove last '*'
        cout << "\b " << endl;
        return;
    }

    // start diving by 2, the first prime number
    if( divisor < START_DIVISOR ) {
        return findFactors(number, START_DIVISOR);
    }

    // if divisor is not prime, add one, try again
    if( !isPrime(divisor) ) {
        return findFactors(number, (divisor+1));
    }

    int remainder = (number % divisor);

    // if divisible, print, then call self with quotient
    if(remainder == 0) {
        cout << divisor << "*";
        int quotient = number / divisor;
        return findFactors(quotient, divisor);
    } else { // else call self with incremented divisor
        return findFactors(number, (divisor+1));
    }
}
