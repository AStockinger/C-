/******************************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Amy Stockinger
 ** Date: 11/5/18
 ** Description: CharacterQueue implementation
 ** includes only required functions, including removing first node, adding
 ** a 'last' node, and printing the queue
******************************************************************************/

#include "CharacterQueue.hpp"
#include <iostream>
using std::cout;
using std::endl;

CharacterQueue::CharacterQueue(){
    head = nullptr;                // queue is empty until elements are added
}

CharacterQueue::~CharacterQueue(){
    while(!isEmpty()){
        if(getFront()->character != nullptr){
            delete getFront()->character;
        }
        delete removeFront();
    }
}

// function returns true if queue is empty
bool CharacterQueue::isEmpty(){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void CharacterQueue::addBack(Character* c, string name, string t){
    Node* n = new Node(c, name, t);
    if(isEmpty()){          // if queue is empty, the added node is the only element, so also it's own prev and next
        head = n;
        head->next = n;
        head->prev = n;
    }
    else{                   // otherwise insert element and make appropriate changes to surrounding prevs and nexts
        Node* temp = head->prev;
        temp->next = n;
        n->prev = temp;
        n->next = head;
        head->prev = n;
    }
}

// returns value of head, if there is one. Otherwise, it returns -1, which is not a valid node value
Node* CharacterQueue::getFront(){
    if(head != nullptr){
        return head;
    }
    else{
        return nullptr;
    }
}

// deletes head node and reassigns it
Node* CharacterQueue::removeFront(){
    if(isEmpty()){              // if empty, there is nothing to remove
        return nullptr;
    }
    Node* temp = head;
    Node* temp2 = head->prev;
    if(head->next != head){     // if head is not the only element
        head = head->next;      // then reassign the head
        head->prev = temp2;     // reassign the new head's previous node
        temp2->next = head;     // and reassign the previous node's next node
    }
    else{
        head = nullptr;
    }
    return temp;
}

void CharacterQueue::moveHeadToBack(){
    if(!isEmpty()){
        head = head->next;
    }
}

// displays current queue with spaces between numbers
void CharacterQueue::printQueue(){
    Node* temp = head;
    if(!isEmpty()){
        cout << head->name << " the " << head->characterType << " ";
        temp = temp->next;
        while(temp != head){
            cout << temp->name << " the " << temp->characterType << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}