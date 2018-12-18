/******************************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Amy Stockinger
 ** Date: 11/5/18
 ** Description: Node specification
 ** contains a character pointer, a name, and prev and next nodes
******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include "Character.hpp"
#include <string>
using std::string;

// node contains a number and pointers to adjacent nodes
struct Node{
    Character* character;
    string name;
    string characterType;
    Node* prev;
    Node* next;
    Node(Character* c, string n, string t){
        character = c;
        name = n;
        characterType = t;
    }
};
#endif