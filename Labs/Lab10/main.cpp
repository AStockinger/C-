/******************************************************************************
 ** Program name: Lab 10
 ** Author: Amy Stockinger
 ** Date: 11/24/18
 ** Description: main function to start test
******************************************************************************/

#include "InputVal.hpp"
#include "Fibonacci.hpp"
#include <iostream>
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */
using std::cout;
using std::endl;

int main(){
    clock_t start;
    int N;

    // get N
    cout << "How many Fibonacci numbers would you like?" << endl;
    getInt(N, 1, 2000000);

    // run iterative
    cout << endl;
    cout << "Calling the non-recursive implementation..." << endl;
    start = clock();
    FibonacciIterative(N);
    start = clock() - start;
    cout << "It took " << static_cast<float>(start)/CLOCKS_PER_SEC << " to run a non-recursive Fibonacci function." << endl;

    // run recursive
    cout << endl;
    cout << "Calling the recursive implementation..." << endl;
    start = clock();
    FibonacciRecursive(N);
    start = clock() - start;
    cout << "It took " << static_cast<float>(start)/CLOCKS_PER_SEC << " to run a recursive Fibonacci function." << endl;

    return 0;
}