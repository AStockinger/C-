/******************************************************************************
 ** Program name: Lab 6
 ** Author: Amy Stockinger
 ** Date: 10/27/18
 ** Description: Node class specification for a doubly linked node containing
 ** an int value
 ** includes getters and setters for data members
******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node{
    private:
        Node* prev;     // points to previous node
        int data;       // integer contained in node
        Node* next;     // points to next node
    public:
        // constructors
        Node();
        Node(int);
        // getters and setters
        int getData();
        Node* getNext();
        void setNext(Node*);
        Node* getPrev();
        void setPrev(Node*);
};
#endif