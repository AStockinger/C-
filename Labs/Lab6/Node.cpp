/******************************************************************************
 ** Program name: Lab 6
 ** Author: Amy Stockinger
 ** Date: 10/27/18
 ** Description: Node class implementation for a doubly linked node containing
 ** an int value
 ** includes getters and setters for data members
******************************************************************************/

#include "Node.hpp"
#include <iostream>

Node::Node(){}

// constructor takes int to be te value, and prev and next are null until set
Node::Node(int a){
    prev = NULL;
    next = NULL;
    data = a;
}

// get data
int Node::getData(){
    return data;
}

// get/set next
Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* a){
    next = a;
}

// get/set prev
Node* Node::getPrev(){
    return prev;
}
void Node::setPrev(Node* a){
    prev = a;
}