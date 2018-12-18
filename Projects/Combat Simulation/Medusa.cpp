/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: Medusa class implementation, includes special glare
** ability implementation
*********************************************************************/


#include "Medusa.hpp"
#include <iostream>

using std::cout;
using std::endl;

// constructor uses Medusa's base stats
Medusa::Medusa() : Character::Character(){
    armor = 3;
    strength = 8;

    attackDiceNum = 2;
    attackDiceSides = 6;
    defenseDiceNum = 1;
    defenseDiceSides = 6;
}

Medusa::~Medusa(){
}

// rolls attack dice
int Medusa::fight(Character* a){
    int damage;
    if(strength > 0){
        damage = diceRoll(attackDiceNum, attackDiceSides);
        cout << getName() << " attack roll: " << damage << endl;
        if(damage == 12){
            cout << "Beware Medusa's glare!" << endl;
            return 100;
        }
        return damage;
    }
    else{
        return 0;
    }
}

string Medusa::getName(){
    return "Medusa";
}