/******************************************************************************
 ** Program name: Lab 7
 ** Author: Amy Stockinger
 ** Date: 11/4/18
 ** Description: Queue specification
 ** includes only required functions, including removing first node, adding
 ** a 'last' node, and printing the queue
******************************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

// node contains a number and pointers to adjacent nodes
struct QueueNode{
    int val;
    QueueNode* prev;
    QueueNode* next;
};

class Queue{
    private:
        QueueNode* head;        // head = designated 'first' node
    public:
        Queue();
        ~Queue();
        bool isEmpty();         // returns true if queue is empty
        void addBack(int);      // adds a node to be previous to head
        int getFront();         // returns value of head
        void removeFront();     // removes head and replaces with next node
        void printQueue();      // displays current queue
};
#endif