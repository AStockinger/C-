/******************************************************************************
 ** Program name: Lab 7
 ** Author: Amy Stockinger
 ** Date: 11/4/18
 ** Description: Menu function implementation
******************************************************************************/

#include "Menu.hpp"
#include "InputVal.hpp"
#include "Queue.hpp"
#include <iostream>
#include <climits>
using std::cout;
using std::endl;

void menu(){
    bool playing = true;
    int choice;
    int num;
    Queue queue;

    // greeting
    cout << "Welcome to my queue!" << endl;

    while(playing){    
        // display menu options
        cout << "Choose from the following options:" << endl;
        cout << "1. Enter a value to be added to the back of the queue" << endl;
        cout << "2. Display the first node value" << endl;
        cout << "3. Remove the first node value" << endl;
        cout << "4. Display the queue contents" << endl;
        cout << "5. Exit" << endl;

        // get user input
        getInt(choice, 1, 5);

        // execute appropriate option
        switch(choice){
            case 1: getInt(num, 0, INT_MAX);
                    queue.addBack(num);
            break;
            case 2: if(queue.getFront() != -1){
                        cout << "The first node value is: " << queue.getFront() << endl;
                    }
                    else{
                        cout << "Your queue is empty." << endl;
                    }
            break;
            case 3: queue.removeFront();
            break;
            case 4: cout << "Your queue is: "; 
                queue.printQueue(); 
                cout << endl;
            break;
            case 5: playing = false;
                    return;
            break;
        }
    }
}