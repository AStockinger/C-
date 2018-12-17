/******************************************************************************
 ** Program name: Lab 10
 ** Author: Amy Stockinger
 ** Date: 11/24/18
 ** Description: Fibonacci functions
 ** source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
******************************************************************************/

#include <iostream>
#include "Fibonacci.hpp"

int FibonacciIterative(int N){
    int first = 0;      // define first 2 fibonacci nums because thats how the rest are calculated
    int second = 1;
    int counter = 2;    // counter is 2 since we already defined the first 2 fibonacci nums

    while(counter < N){
        int temp = second;          // hold one number in a temp since one is used to calculate two
        second = first + second;    // change the second num
        first = temp;               // now change the first
        counter++;
    }
    if(N == 0){                     // if N = 0, then return 0 as nothing
        return 0;
    }
    else{                           // else return the preceding two fibonacci nums added to make the Nth num
        return first + second;
    }
}

int FibonacciRecursive(int N){
    if(N == 0 || N == 1){           // the base cases
        return N;
    }
    else{
        return FibonacciRecursive(N - 1) + FibonacciRecursive(N - 2);
    }
}