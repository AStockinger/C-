/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Space implementation
******************************************************************************/

#include "Space.hpp"
#include <iostream>

using std::cout;
using std::endl;

// all adjacent spaces are NULL until assigned
Space::Space(){
    setUp(NULL);
    setRight(NULL);
    setDown(NULL);
    setLeft(NULL);
}

Space::~Space(){

}

Space* Space::getUp(){
    if(up != NULL){
        return up;
    }
    else{
        return NULL;
    }
}
Space* Space::getRight(){
    if(right != NULL){
        return right;
    }
    else{
        return NULL;
    }
}
Space* Space::getDown(){
    if(down != NULL){
        return down;
    }
    else{
        return NULL;
    }
}
Space* Space::getLeft(){
    if(left != NULL){
        return left;
    }
    else{
        return NULL;
    }
}

void Space::setUp(Space* here){
    up = here;
}
void Space::setRight(Space* here){
    right = here;
}
void Space::setDown(Space* here){
    down = here;
}
void Space::setLeft(Space* here){
    left = here;
}