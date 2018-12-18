/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
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
            cout << getName() << " defense roll: " << def << endl;
            cout << getName() << " armor: 1, current strength: " << strength << endl;
        }
        // total defense is the roll plus character's armor
        int totalDef = def + armor;
        int totalDamage = damage - totalDef;
        // damage cannot be 'negative'
        if(totalDamage < 0){
            totalDamage = 0;
        }
        cout << getName() << " takes " << totalDamage << " damage." << endl; 

        setStrength(strength - totalDamage);

        if(strength <= 0){
            setStrength(0);
            cout << "Oh no! " << getName() << " is out of strength." << endl;
        }
        else{
            cout << getName() << " has " << strength << " strength left." << endl;
        }
    }
    else{
        if(damage == 100){
            damage = 0;
            cout << "Medusa's glare is no match for Vampire's charm!" << endl;
        }
        else
            cout << "The opponent was charmed into not attacking " << getName() << "." << endl;
            cout << getName() << " has " << strength << " strength left." << endl;
    }
    cout << endl;
}

string Vampire::getName(){
    return "Vampire";
}