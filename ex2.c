//318731007 Ben Ganon

#include "ex2.h"
#include <limits.h>
#include <stdio.h>

/*
 * throughout this exercise there is frequent use of INT_MIN and INT_MAX-
 * the reason for this is INT_MIN is a convenient mask for 1000000...
 * and INT_MAX is a convinient mask for 01111111...
 * both are used to turn the msb on and off,
 * because in magnitude that is how you receive the absolute value of the number.
 * most of the calculations below use this fact to display the correct overflow values that are incorrect in
 * Two's compliment.
 */

/**
 * adds a to b in magnitude
 * @param a magnitude
 * @param b magnitude
 * @return magnitude a+b
 */
magnitude add(magnitude a, magnitude b) {
    //cast both numbers to int for calculation
    int aInt = toInt(a);
    int bInt = toInt(b);
    //if the addition creates positive overflow we manually reset it
    //INT_MAX is used as a mask that shuts off the msb and returns to positive
    if (aInt > 0 && bInt > 0 && (aInt + bInt) <= 0) {
        return (a + b) & INT_MAX;
    }
    //otherwise if the overflow is negative we make sure it stays negative via INT_MIN mask
    else if (aInt < 0 && bInt < 0 && (aInt + bInt) >= 0) {
        return (a + b) | INT_MIN;
    }
    //if no overflow occured return the regular addition
    else return toMagnitude(aInt + bInt);

}

/**
 * subtracts b from a
 * @param a magnitude
 * @param b magnitude
 * @return magnitude a-b
 */
magnitude sub(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    //turn b into negative
    bInt = -bInt;
    //return the result of the addition with -b
    return add(toMagnitude(aInt), toMagnitude(bInt));
}
/**
 * multiplies a by b
 * @param a magnitude
 * @param b magnitude
 * @return magnitude a*b
 */
magnitude multi(magnitude a, magnitude b) {
    //receiveing the absolute value of a and b
    magnitude posA = a & INT_MAX;
    magnitude posB = b & INT_MAX;
    //saving the sign
    int sign = (a ^ b) & INT_MIN;
    //returning the positive regular multiplication with the sign pushed to msb
    return ((posA * posB) & INT_MAX) | sign;
}

/**
 * checks if a equals b
 * @param a magnitude
 * @param b magnitude
 * @return magnitude a == b
 */
int equal(magnitude a, magnitude b) {
    //converting both nums to int to remove double 0 value
    int aInt = toInt(a);
    int bInt = toInt(b);
    //saving the comparison result
    int c = aInt == bInt;
    return c;
}
/**
 * checks if a equals b
 * @param a magnitude
 * @param b magnitude
 * @return magnitude a == b
 */
int greater(magnitude a, magnitude b) {
    //converting both nums to int to remove double 0
    int aInt = toInt(a);
    int bInt = toInt(b);
    //saving and returning the evaluation
    int c = aInt > bInt;
    return c;
}

/**
 * converts int to magnitude
 * @param x int
 * @return magnitude x
 */
magnitude toMagnitude(int x) {
    //magnitude and int are identical when representing positive numbers
    if (x >= 0) {
        return x;
    }
    //if x is negative we cast it to it's positive version so it aligns with the representation of magnitude
    x = -x;
    //we return it with the msb changed to 1
    return x | INT_MIN;
}

/**
 * converts magnitude to int
 * @param x magnitude
 * @return int x
 */
int toInt(magnitude x) {
    //checking if the number is positive via it's msb
    if (!(x & INT_MIN)) {
        return x;
    }
    int z = x & INT_MAX;
    return -z;
}
