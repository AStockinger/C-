/******************************************************************************
 ** Program name: Lab 5
 ** Author: Amy Stockinger
 ** Date: 10/20/18
 ** Description: Recursive Functions implementation
 ** StackOverflow on substrings:
 https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string
******************************************************************************/

#include "RecursiveFunctions.hpp"
#include "InputVal.hpp"
#include <iostream>
#include <climits>
using std::cout;
using std::cin;
using std::endl;

// reverses a string by inputting chars into a char array in reverse
void reverseString(string aString){
    int length = aString.length();

    // base case: empty string AKA length of 0
    if(length == 0){
        cout << endl;
        return;
    }
    // otherwise print length - 1 (because an array starts at 0 but length doesn't)
    if(length != 0){
        cout << aString[length - 1];
        // then call function again with the same string minus the char that was just printed
        return reverseString(aString.substr(0, aString.length() - 1));
    }
}
// calls respective function and prompts user
void pickReverseStr(){
    string input;
    cout << "Please enter a string to be reversed." << endl;
    getline(cin, input);
    reverseString(input);
}


// sums the ints of an array
int sumArray(int* intArray, int elements){
    // base case is when the number of elements is zero
    if(elements == 0){
        return 0;
    }
    // otherwise, return this element + the next element (counting down to 0)
    else{
        return intArray[elements - 1] + sumArray(intArray, elements - 1);
    }
}
// will sum intergers for the user; min input is 2 so there is actually a sum to be computed
void pickSumArray(){
    int size, choice; 
    int counter = 0;
    int *intArray = nullptr;

    cout << "How many integers would you like to sum?" << endl;
    getInt(size, 2, INT_MAX);
    intArray = new int[size];

    cout << "Enter numbers to be summed." << endl;
    while(counter != size){
        getInt(choice, 0, INT_MAX);
        intArray[counter] = choice;
        counter++;
    }
    cout << sumArray(intArray, size) << endl;
    delete[] intArray;
}


// returns one number that is the triangular of the inputted number
// triangular appears to be the sum of the inputted number and all previous numbers down to 1
int triangularNum(int n){
    // base case, T1 = 1
    if(n == 1){
        return 1;
    }
    else{
        return n + triangularNum(n - 1);
    }
}
// prompts for triangular
void pickTriangular(){
    int choice;
    cout << "Enter a number to get its triangular number." << endl;
    getInt(choice, 1, 99999);
    cout << "The triangular of " << choice << " is: " << triangularNum(choice) << endl;
}
