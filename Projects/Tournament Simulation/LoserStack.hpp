/******************************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Amy Stockinger
 ** Date: 11/5/18
 ** Description: Loser Stack specification
 ** 
******************************************************************************/

#ifndef LOSERSTACK_HPP
#define LOSERSTACK_HPP

#include "Node.hpp"

class LoserStack{
    private:
        Node* head; // head pointer for first node in list
        Node* tail; // tail pointer for last node in list
    public:
        LoserStack();             
        ~LoserStack();
        void addHeadNode(Node*);      // add a node to front of list
        void printList();                  // print list
};
#endif