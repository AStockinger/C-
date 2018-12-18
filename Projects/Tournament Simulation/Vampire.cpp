/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Vampire class implementation, includes special charm
** ability implementation
*********************************************************************/

#include "Vampire.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;

// constructor uses Vampire's base stats
Vampire::Vampire() : Character::Character(){
    armor = 1;
    strength = 18;
    maxHP = 18;

    attackDiceNum = 1;
    attackDiceSides = 12;
    defenseDiceNum = 1;
    defenseDiceSides = 6;
}

Vampire::~Vampire(){

}
// rolls defense dice to calculate total damage from an attack
void Vampire::damage(int damage){
    int chance = rand() % 2;
    
    if(chance == 0){
        int def = 0;
        if(strength > 0){
            // get defensive roll number
            def = diceRoll(defenseDiceNum, defenseDiceSides);
        }
        // total defense is the roll plus character's armor
        int totalDef = def + armor;
        int totalDamage = damage - totalDef;
        // damage cannot be 'negative'
        if(totalDamage < 0){
            totalDamage = 0;
        }

        setStrength(strength - totalDamage);

        if(strength <= 0){
            setStrength(0);
        }
    }
    else{
        if(damage == 100){
            damage = 0;
        }
    }
}

string Vampire::getName(){
    return "Vampire";
}