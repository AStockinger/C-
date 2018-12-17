/******************************************************************************
 ** Program name: Lab 7
 ** Author: Amy Stockinger
 ** Date: 11/4/18
 ** Description: Queue implementation
 ** includes only required functions, including removing first node, adding
 ** a 'last' node, and printing the queue
******************************************************************************/

#include "Queue.hpp"
#include <iostream>
using std::cout;
using std::endl;

Queue::Queue(){
    head = nullptr;     // queue is empty until elements are added
}

Queue::~Queue(){
    while(head != nullptr){
        removeFront();
    }
}

// function returns true if queue is empty
bool Queue::isEmpty(){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Queue::addBack(int v){
    QueueNode* temp = new QueueNode;
    if(isEmpty()){          // if queue is empty, the added node is the only element, so also it's own prev and next
        head = temp;
        head->next = head;
        head->prev = head;
        head->val = v;
    }
    else{                   // otherwise insert element and make appropriate changes to surrounding prevs and nexts
        QueueNode* n = head->prev;
        temp->next = head;
        head->prev = temp;
        temp->prev = n;
        n->next = temp;
        temp->val = v;
    }
}

// returns value of head, if there is one. Otherwise, it returns -1, which is not a valid node value
int Queue::getFront(){
    if(head != nullptr){
        return head->val;
    }
    else{
        return -1;
    }
}

// deletes head node and reassigns it
void Queue::removeFront(){
    if(isEmpty()){              // if empty, there is nothing to remove
        return;
    }
    QueueNode* temp = head;
    QueueNode* temp2 = head->prev;
    if(head->next != head){     // if head is not the only element
        head = head->next;      // then reassign the head
        head->prev = temp2;     // reassign the new head's previous node
        temp2->next = head;     // and reassign the previous node's next node
    }
    else{
        head = nullptr;
    }
    delete temp;
}

// displays current queue with spaces between numbers
void Queue::printQueue(){
    QueueNode* temp = head;
    if(!isEmpty()){
        cout << head->val << " ";
        temp = temp->next;
        while(temp != head){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}