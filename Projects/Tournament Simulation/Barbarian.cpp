/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Barbarian class implementation, inherits Character
** straightforward class with no special abilities
*********************************************************************/

#include "Barbarian.hpp"

// constructor uses Barbarian's base stats
Barbarian::Barbarian() : Character::Character(){
    armor = 0;
    strength = 12;
    attackDiceNum = 2;
    attackDiceSides = 6;
    defenseDiceNum = 2;
    defenseDiceSides = 6;
    maxHP = 12;
}

Barbarian::~Barbarian(){

}

string Barbarian::getName(){
    return "Barbarian";
}