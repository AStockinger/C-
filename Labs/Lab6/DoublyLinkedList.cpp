/******************************************************************************
 ** Program name: Lab 6
 ** Author: Amy Stockinger
 ** Date: 10/27/18
 ** Description: Linked List implementation
 ** functions to add to/delete from each side of the list, as well as print
 ** the first/last values, and all values forward and backward.
******************************************************************************/

#include "DoublyLinkedList.hpp"
#include "InputVal.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;

// constructor is an empty list where head and tail are null
DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

// destructor traverses the list and deleted nodes until it gets to null
DoublyLinkedList::~DoublyLinkedList(){
    Node* current = head;           // make a pointer to current head
    while(current != NULL){
        head = head->getNext();     // now set head pointer to be the next node
        delete current;             // delete previous head
        current = head;             // set pointer to head again, then loop until null
    }
}

// add a node to the front of the list
void DoublyLinkedList::addHeadNode(int a){
    Node* temp = new Node(a);       // make a new node
    if(head != NULL){               // if there is a node in the list, make temp the head by:
        head->setPrev(temp);        // setting previous head to be previous to the new head
        temp->setNext(head);        // setting the previous head to next for new head
        temp->setPrev(NULL);        // set new head's next to null
    }
    if(tail == NULL){               // consider the tail, if it was an empty list before
        tail = temp;                // if there is only one node, it is the head and the tail
    }
    head = temp;                    // now move head pointer to temp
}

// add a node to the back of the list
void DoublyLinkedList::addTailNode(int a){
    Node* temp = new Node(a);           // make new node
    if(tail != NULL && head != NULL){   // if there is a node in the list,
        tail->setNext(temp);            // set the previous tail's next to be the new tail
        temp->setPrev(tail);            // set the new tail's previous to be the previous tail
        temp->setNext(NULL);            // set new tail's next to null
    }
    else if(head == NULL){              // consider the head, if it was an empty list before
        head = temp;                    // if there is only one node, it is the head and the tail
    }
    tail = temp;                        // now move tail pointer to temp
}

// delete first node in list
void DoublyLinkedList::deleteFirstNode(){
    if(head == NULL){               // if empty list, do nothing
        return;
    }
    else if(head->getNext() == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{                       
        Node* temp = head;          // make a temp pointer to first link
        head = head->getNext();     // point head to second link
        head->setPrev(NULL);        // unlink previous head
        delete temp;                // delete previous head
    }
}

// delete last node in list
void DoublyLinkedList::deleteLastNode(){
    if(tail == NULL){               // if empty list, do nothing
        return;
    }
    else if(tail->getPrev() == NULL || head->getNext() == NULL){
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else{                           // if not empty list
        Node* temp = tail;          // make a pointer to tail
        tail = tail->getPrev();     // then set tail to its previous node
        tail->setNext(NULL);        // set new tail's next node to null
        delete temp;                // delete original tail
    }
}

// print list backwards
void DoublyLinkedList::traverseReversely(){
    // message if list is empty
    if(head == NULL){
        cout << "The list is empty." << endl;
    }
    else{
        Node* current = tail;                   // start at tail
        while(current != head){                 
            cout << current->getData() << " ";  // print value
            current = current->getPrev();       // then go to the previous, and loop until null
        }
        cout << head->getData();
        cout << endl;
    }
}

// print list forward
void DoublyLinkedList::traverse(){
    // message if list is empty
    if(head == NULL){
        cout << "The list is empty." << endl;
    }
    // traverse list by making a pointer to go down the list until it finds a node where next is null
    else{
        Node* current = head;                   // start at head
        while(current != NULL){
            cout << current->getData() << " ";  // print value
            current = current->getNext();       // set current to next, and loop until null
        }
        cout << endl;
    }
}

// print first node
void DoublyLinkedList::printNodeHead(){
    if(head == NULL){
        cout << "The list is empty." << endl;
    }
    else{
        cout << head->getData() << endl;
    }
}

// print last node
void DoublyLinkedList::printNodeTail(){
    if(head == NULL){
        cout << "The list is empty." << endl;
    }
    else{
        cout << tail->getData() << endl;
    }
}

void DoublyLinkedList::readFromFile(){
    int notify, num;
    cout << "This will delete the current list, press 1 to continue or 2 to return." << endl;
    getInt(notify, 1, 2);

    if(notify == 2){
        return;
    }
    else{
        ifstream inputFile;
        inputFile.open("linkedlist.txt");
        if(inputFile){
            // delete current list
            Node* current = head;               // make a pointer to current head
            if(head != NULL){
                while(current != NULL){
                    head = head->getNext();     // now set head pointer to be the next node
                    delete current;             // delete previous head
                    current = head;             // set pointer to head again, then loop until null
                }
            }

            while(inputFile >> num){
                addTailNode(num);
            }
            inputFile.close();
        }
        else{
            cout << "File not found." << endl;
        }
    }
}