/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: BlueMen class implementation
** includes mob ability that will decrease defense dice each time 1/3
** of strength is lost
*********************************************************************/

#include "BlueMen.hpp"
#include <iostream>
using std::cout;
using std::endl;

// constructor uses Blue Men's base stats
BlueMen::BlueMen() : Character::Character(){
    armor = 3;
    strength = 12;

    attackDiceNum = 2;
    attackDiceSides = 10;
    defenseDiceNum = 3;
    defenseDiceSides = 6;
}

BlueMen::~BlueMen(){

}

// rolls defense dice to calculate total damage from an attack
void BlueMen::damage(int damage){
    int def = 0;
    if(strength > 0){
        // get defensive roll number
        def = diceRoll(defenseDiceNum, defenseDiceSides);

        cout << getName() << " defense roll: " << def << endl;
        cout << getName() << " " << armor << ": 3, current strength: " << strength << endl;
    }
    // total defense is the roll plus character's armor
    int totalDef = def + armor;
    int totalDamage = damage - totalDef;
    // damage cannot be 'negative'
    if(totalDamage < 0){
        totalDamage = 0;
    }
    cout << getName() << " take " << totalDamage << " damage!" << endl;

    // lose defense dice for every 4 points of damage
    if(strength == 8 || strength == 4){
        setDefDice(getDefDice() - 1);
        cout << "Oh no! " << getName() << " lost a defense die." << endl;
    }
    setStrength(strength - totalDamage);

    if(strength <= 0){
        setStrength(0);
        cout << "Oh no! " << getName() << " are out of strength." << endl;
    }
    else{
        cout << getName() << " have " << strength << " strength left." << endl;
    }

    cout << endl;
}

void BlueMen::setDefDice(int a){
    defenseDiceNum = a;
}

int BlueMen::getDefDice(){
    return defenseDiceNum;
}

string BlueMen::getName(){
    return "Blue Men";
}