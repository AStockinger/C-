/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Character class implementation, abstract base class
** for fighter types
** each fighter has unique combination of strength, armor and dice
*********************************************************************/

#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;

Character::Character(){
}

Character::~Character(){
}

// rolls specified number of dice with specified sides and returns total
int Character::diceRoll(int numDice, int sides){
    // total of dice rolls
    int total = 0;

    for(int i = 0; i < numDice; i++){
        int roll = (rand() % sides) + 1;
        total += roll;
    }
    return total;
}

// rolls attack dice
int Character::fight(Character* a){
    int attack = 0;
    if(strength > 0){
        attack = diceRoll(attackDiceNum, attackDiceSides);
        return attack;
    }
    else{
        return 0;
    }
}

// rolls defense dice to calculate total damage from an attack
void Character::damage(int damage){
    int def = 0;
    if(strength > 0){
        // get defensive roll number
        def = diceRoll(defenseDiceNum, defenseDiceSides);
    }
    // subtract defense roll from damage opponent tried to inflict to get actual damage done
    int totalDamage = damage - def;

    // damage cannot be negative
    if(totalDamage < 0){
        totalDamage = 0;
    }

    // set health to reflect damage taken
    setStrength(strength - totalDamage);

    // if health is 0 or less, the character is out
    if(strength <= 0){
        setStrength(0);
    }
}

// character strength getter/setter
int Character::getStrength(){
    return strength;
}      
void Character::setStrength(int s){
    strength = s;
}

// heals character a random amount between 1 and total damage accumulated
void Character::heal(){
    if(strength < maxHP){
        int recovery = rand() % (maxHP - strength) + 1;
        strength += recovery;
    }
}