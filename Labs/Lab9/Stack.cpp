/******************************************************************************
 ** Program name: Lab 9
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Stack implementation includes a constructor to take in a 
 ** string, and a palindrome function to pop off the stack and make a palindrome
******************************************************************************/

#include "Stack.hpp"
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

// stack takes in a string to store it in the stack
Stack::Stack(string input){
    userInput = input;
    for(unsigned int i = 0; i < input.length(); i++){
        someString.push(input[i]);
    }
}

// outputs original string and the characters popped off the stack to make a palindrome
void Stack::palindrome(){
    cout << "The palindrome is: ";
    cout << userInput;
    while(!someString.empty()){
        cout << someString.top();
        someString.pop();
    }
    cout << endl;
}
