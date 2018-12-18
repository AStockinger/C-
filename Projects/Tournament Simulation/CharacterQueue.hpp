/******************************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Amy Stockinger
 ** Date: 11/5/18
 ** Description: CharacterQueue specification
 ** includes only required functions, including removing first node, adding
 ** a 'last' node, and printing the queue
******************************************************************************/


#ifndef CHARACTERQUEUE_HPP
#define CHARACTERQUEUE_HPP

#include "Node.hpp"

class CharacterQueue{
    private:
        Node* head;                                     // head = designated 'first' node
    public:
        CharacterQueue();
        ~CharacterQueue();
        bool isEmpty();                                 // returns true if queue is empty
        void addBack(Character*, string, string);       // adds a node to be previous to head
        Node* getFront();                               // returns  head
        Node* removeFront();                            // removes and returns head, to be placed in loser stack
        void moveHeadToBack();
        void printQueue();                              // displays current queue
};
#endif