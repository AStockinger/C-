/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: Harry Potter class implementation
** includes bool for Harry's second life, along with getter and setter
*********************************************************************/


#include "HarryPotter.hpp"
#include <iostream>
using std::cout;
using std::endl;

// constructor uses Harry Potter's base stats and second life is false
HarryPotter::HarryPotter() : Character::Character(){
    armor = 0;
    strength = 10;

    attackDiceNum = 2;
    attackDiceSides = 6;
    defenseDiceNum = 2;
    defenseDiceSides = 6;

    secondLife = false;
}

HarryPotter::~HarryPotter(){

}

// for HP Hogwarts ability; will become true when HP dies the first time
void HarryPotter::setLife(bool life){
    secondLife = life;
}
bool HarryPotter::getLife(){
    return secondLife;
}

// rolls defense dice to calculate total damage from an attack
void HarryPotter::damage(int damage){
    int def = 0;
    if(strength > 0){
        // get defensive roll number
        def = diceRoll(defenseDiceNum, defenseDiceSides);
        cout << getName() << " defense roll: " << def << endl;
        cout << getName() << " armor: " << armor << ", current strength: " << strength << endl;
    }

    // Harry has no armor to consider
    int totalDamage = damage - def;

    if(totalDamage < 0){
        totalDamage = 0;
    }

    cout << getName() << " takes " << totalDamage << " damage." << endl;

    // subtract total damage from total strength
    setStrength(strength - totalDamage);

    // determine if Harry is still alive and has his second life
    if(strength <= 0 && getLife() == true){
        setStrength(0);
        cout << "Oh no! " << getName() << " is out of strength." << endl;
    }
    else if(strength <= 0 && getLife() == false){
        setLife(true);
        setStrength(20);
        cout << getName() << " has come back to life! He has 20 strength left." << endl;
    }
    else{
        cout << getName() << " has " << strength << " strength left." << endl;
    }
    cout << endl;
}

string HarryPotter::getName(){
    return "Harry Potter";
}