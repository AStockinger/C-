/******************************************************************************
 ** Program name: Lab 5
 ** Author: Amy Stockinger
 ** Date: 10/20/18
 ** Description: Recursive Functions specification
******************************************************************************/

#ifndef RECURSIVE_FUNCTIONS_HPP
#define RECURSIVE_FUNCTIONS_HPP

#include <string>
using std::string;

// reverses a string by inputting chars into a char array in reverse
void reverseString(string aString);
// helper function to prompt reverse string
void pickReverseStr();


// sums the ints of an array
int sumArray(int* array, int elements);
// helper function to prompt sumArray
void pickSumArray();


// returns one number that is the triangular of the inputted number
int triangularNum(int n);
// helper function to prompt triangularNum
void pickTriangular();

#endif
