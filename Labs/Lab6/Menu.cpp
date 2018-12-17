/******************************************************************************
 ** Program name: Lab 6
 ** Author: Amy Stockinger
 ** Date: 10/27/18
 ** Description: Menu function implementation
******************************************************************************/

#include "Menu.hpp"
#include "InputVal.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>
#include <climits>
using std::cout;
using std::endl;

void menu(){
    bool playing = true;
    int choice;
    int num;
    DoublyLinkedList list;

    cout << "Welcome to my linked list!" << endl;
    cout << "**This program includes both extra credit options**" << endl;

    while(playing){    
        cout << "Choose from the following options:" << endl;
        cout << "1. Add new node to the head" << endl;
        cout << "2. Add new node to the tail" << endl;
        cout << "3. Delete from head" << endl;
        cout << "4. Delete from tail" << endl;
        cout << "5. Traverse the list reversely" << endl;
        cout << "6. Print value of head node" << endl;
        cout << "7. Print value of tail node" << endl;
        cout << "8. Read list from file" << endl;
        cout << "9. Quit" << endl;

        getInt(choice, 1, 9);

        switch(choice){
            case 1: getInt(num, 0, INT_MAX);
                list.addHeadNode(num);
                list.traverse();
            break;
            case 2: getInt(num, 0, INT_MAX);
                list.addTailNode(num);
                list.traverse();
            break;
            case 3: list.deleteFirstNode();
                list.traverse();
            break;
            case 4: list.deleteLastNode();
                list.traverse();
            break;
            case 5: list.traverseReversely();
            break;
            case 6: list.printNodeHead();
            break;
            case 7: list.printNodeTail();
            break;
            case 8: list.readFromFile();
                list.traverse();
            break;
            case 9: cout << "Goodbye!" << endl;
                playing = false;
                return;
            break;
        }
    }
}