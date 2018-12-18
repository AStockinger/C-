/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: Barbarian class implementation, inherits Character
** straightforward class with no special abilities
*********************************************************************/

#include "Barbarian.hpp"
#include <iostream>

using std::cout;
using std::endl;

// constructor uses Barbarian's base stats
Barbarian::Barbarian() : Character::Character(){
    armor = 0;
    strength = 12;
    attackDiceNum = 2;
    attackDiceSides = 6;
    defenseDiceNum = 2;
    defenseDiceSides = 6;
}

Barbarian::~Barbarian(){

}

string Barbarian::getName(){
    return "Barbarian";
}