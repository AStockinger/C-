/******************************************************************************
 ** Program name: Lab 6
 ** Author: Amy Stockinger
 ** Date: 10/27/18
 ** Description: Linked List specification
 ** functions to add to/delete from each side of the list, as well as print
 ** the first/last values, and all values forward and backward.
******************************************************************************/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class DoublyLinkedList{
    private:
        Node* head; // head pointer for first node in list
        Node* tail; // tail pointer for last node in list
    public:
        DoublyLinkedList();             
        ~DoublyLinkedList();
        void addHeadNode(int);      // add a node to front of list
        void addTailNode(int);      // add a node to back of list
        void deleteFirstNode();     // remove a node from front of list
        void deleteLastNode();      // remove a node from back of list
        void traverseReversely();   // print list backwards
        void traverse();            // print list
        // extra credit
        void printNodeHead();       // print first node
        void printNodeTail();       // print last node
        void readFromFile();        // read list from input file
};
#endif