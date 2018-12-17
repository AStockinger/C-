/******************************************************************************
 ** Program name: Lab 9
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: main to initiate program
******************************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Queue.hpp"
#include "Stack.hpp"
#include "InputVal.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){
    srand(time(NULL));      // random seed for queue
    int choice = 0;

    while(choice != 3){
        cout << "** Welcome to my STL containers **" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Queue simulation" << endl;
        cout << "2. Stack string palindrome" << endl;
        cout << "3. Exit" << endl;
        getInt(choice, 1, 3);

        switch(choice){
            case 1: {
                // get user numbers
                int rounds, percentageAdd, percentageRemove;
                Queue myQueue;
                cout << "How many rounds for the simulation?" << endl;
                getInt(rounds, 1, 3000);
                cout << "Enter a percent chance to add a random number to the end of the buffer." << endl;
                getInt(percentageAdd, 1, 100);
                cout << "Enter a percent chance to remove a number from the front of the buffer." << endl;
                getInt(percentageRemove, 1, 100);
                // run simulation
                myQueue.simulation(rounds, percentageAdd, percentageRemove);
            }
            break;
            case 2: {
                // get user input
                string input;
                cout << "Please enter a string." << endl;
                getline(cin, input);
                // make stack and palindrome
                Stack myStack(input);
                myStack.palindrome();
            }
            break;
            case 3: cout << "Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}