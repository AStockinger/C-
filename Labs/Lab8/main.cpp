/******************************************************************************
 ** Program name: Lab 8
 ** Author: Amy Stockinger
 ** Date: 11/11/18
 ** Description: main to initiate program
******************************************************************************/

#include "SearchAndSort.hpp"
#include "InputVal.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    int val; 
    string file1, file2, file3, file4;

    cout << "What is the search target value? Note: for this assignment, I used 0." << endl;
    getInt(val, 0, 40000);
    cout << endl;

    simpleSearch(val, "randomNums.txt");
    simpleSearch(val, "early.txt");
    simpleSearch(val, "middle.txt");
    simpleSearch(val, "end.txt");

    file1 = sort("randomNums.txt");
    file2 = sort("early.txt");
    file3 = sort("middle.txt");
    file4 = sort("end.txt");

    binarySearch(val, file1);
    binarySearch(val, file2);
    binarySearch(val, file3);
    binarySearch(val, file4);

    return 0;
}