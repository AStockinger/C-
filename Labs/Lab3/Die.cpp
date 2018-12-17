/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Die class implementation
 ** Class simulates a game die by taking in a number to represent sides,
 ** and returns a random number between 1 and sides with the roll function.
******************************************************************************/

#include "Die.hpp"
#include <stdlib.h>
#include <time.h>

// default constructor
Die::Die(){}

// inputted number is sides
Die::Die(int sides){
    N = sides;
}

Die::~Die(){}

// a roll returns a random number between 1 and sides
int Die::roll(){
    return (rand() % N) + 1;
}

// returns sides of die
int Die::getSides(){
    return N;
}

// returns die type as a string
string Die::getType(){
    return "normal";
}