/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
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
        cout << getName() << " Attack roll: " << attack << endl;
        return attack;
    }
    else{
        cout << getName() << " has no strength left to attack." << endl;
        return 0;
    }
}

// rolls defense dice to calculate total damage from an attack
void Character::damage(int damage){
    int def = 0;
    if(strength > 0){
        // get defensive roll number
        def = diceRoll(defenseDiceNum, defenseDiceSides);
        cout << getName() << " Defense roll: " << def << endl;
        cout << getName() << " armor: " << armor << ", current strength: " << strength << endl;
    }
    // subtract defense roll from damage opponent tried to inflict to get actual damage done
    int totalDamage = damage - def;

    // damage cannot be negative
    if(totalDamage < 0){
        totalDamage = 0;
    }

    cout << getName() << " takes " << totalDamage << " damage!" << endl;

    // set health to reflect damage taken
    setStrength(strength - totalDamage);

    // if health is 0 or less, the character is out
    if(strength <= 0){
        setStrength(0);
        cout << "Oh no! " << getName() << " is out of strength." << endl;
    }
    else{
        cout << getName() << " has " << strength << " strength left." << endl;
    }
    cout << endl;
}

// character strength getter/setter
int Character::getStrength(){
    return strength;
}      
void Character::setStrength(int s){
    strength = s;
}