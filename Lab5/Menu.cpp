/******************************************************************************
 ** Program name: Lab 5
 ** Author: Amy Stockinger
 ** Date: 10/20/18
 ** Description: Menu function allows user to pick recursive function to use
******************************************************************************/

#include "RecursiveFunctions.hpp"
#include "InputVal.hpp"
#include <iostream>
using std::cout;
using std::endl;

void mainMenu(){
    int choice;
    bool playing = true;

    while(playing){
        cout << "What would you like to do?" << endl;
        cout << "1. Pick a string to reverse" << endl;
        cout << "2. Calculate the sum of integers" << endl;
        cout << "3. Calculate the triangular number of an integer" << endl;
        cout << "4. Quit" << endl;
        getInt(choice, 1, 4);

        switch(choice){
            case 1: pickReverseStr();
            break;
            case 2: pickSumArray();
            break;
            case 3: pickTriangular();
            break;
            case 4: playing = false;
            return;
        }
    }
 }