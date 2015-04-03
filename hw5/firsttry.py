from math import sqrt
from math import floor

def isPrime(dividend, divisor=0):
    '''isPrime determines (recursively) whether a number (the dividend)
    is prime by dividing by half the dividend, then
    consecutively smaller.  It is terribly inefficient.'''

    # zero is neither prime nor composite
    if dividend == 0:
        return False

    square_root = sqrt(dividend)
    close_to_square_root = floor(square_root)

    # let's not divide by zero, this was probably the
    # default parameter, let's start at the top
    if divisor == 0:
        return isPrime(dividend, close_to_square_root)

    # if we get to this point, dividend is prime.
    if divisor <= 1:
        return True

    # from from sqrt(dividend) on down
    if divisor > square_root:
        return isPrime(dividend, close_to_square_root)

    remainder = dividend % divisor

    if remainder == 0:
        return False
    else:
        return isPrime(dividend, (divisor-1))

test_numbers = [5, 7, 11, 19, 21, 4, 13]

for num in test_numbers:
    print "is {0} prime? {1}".format(num, isPrime(num))

isPrime(5)
