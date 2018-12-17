/******************************************************************************
 ** Program name: Lab 9
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Stack specification includes a constructor to take in a 
 ** string, and a palindrome function to pop off the stack and make a palindrome
******************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stack>
#include <string>
using std::string;
using std::stack;

class Stack{
    private:
        stack<char> someString;     // the stack
        string userInput;           // store user input
    public:
        Stack(string);
        void palindrome();          // pops off stack to make palindrome
};

#endif