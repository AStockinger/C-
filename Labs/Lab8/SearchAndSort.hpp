/******************************************************************************
 ** Program name: Lab 8
 ** Author: Amy Stockinger
 ** Date: 11/11/18
 ** Description: search and sort function headers, including reading a file 
 ** into an array, a simple search, a sort, and a binary search
******************************************************************************/

#ifndef SEARCHANDSORT_HPP
#define SEARCHANDSORT_HPP

#include <fstream>
#include <string>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::string;

// creates an array from data of a txt file
int readFromFile(string, int*);

// performs simple search for each required file
void simpleSearch(int, string);

// prints output values as well as places them into output files
string sort(string);
void bubbleSort(int[], int);

// performs simple search for each required file
void binarySearch(int, string);

#endif