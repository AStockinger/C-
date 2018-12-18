/******************************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Amy Stockinger
 ** Date: 11/5/18
 ** Description: Loser Stack implementation
 ** 
******************************************************************************/

#include "InputVal.hpp"
#include "LoserStack.hpp"
#include <iostream>
using std::cout;
using std::endl;

// constructor is an empty list where head and tail are null
LoserStack::LoserStack(){
    head = nullptr;
    tail = nullptr;
}

// destructor traverses the list and deleted nodes until it gets to null
LoserStack::~LoserStack(){
    Node* current = head;           // make a pointer to current head
    while(current != tail){
        head = head->next;          // now set head pointer to be the next node
        if(current->character != nullptr){
            delete current->character;
        }
        delete current;             // delete previous head
        current = head;             // set pointer to head again, then loop until null
    }
    delete tail->character;
    delete tail;
}

// add a node to the front of the list
void LoserStack::addHeadNode(Node* a){
    if(head != nullptr){              
        head->prev = a;        
        a->next = head; 
        a->prev = nullptr;        
    }
    if(tail == nullptr){               // consider the tail, if it was an empty list before
        tail = a;                
    }
    head = a;                    
}

// print list forward
void LoserStack::printList(){
    // message if list is empty
    if(head == nullptr){
        cout << "The list is empty." << endl;
    }
    // traverse list by making a pointer to go down the list until it finds a node where next is null
    else{
        Node* current = head;                   // start at head
        while(current != tail){
            cout << current->name << " the " << current->characterType << endl;
            current = current->next;       // set current to next, and loop until null
        }
        current = tail;
        cout << current->name << " the " << current->characterType << endl;
        cout << endl;
    }
}