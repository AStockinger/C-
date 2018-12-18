/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Character class specification, abstract base class
** for fighter types
** each fighter has unique combination of strength, armor and dice
*********************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using std::string;

class Character{
    protected:
        // to be set for each different character type according to given stats
        int attackDiceNum, attackDiceSides, defenseDiceNum, defenseDiceSides, armor, strength;
        int maxHP;
    public:
        Character();
        virtual ~Character();
        // simulates dice rolls, rand seed in menu function
        int diceRoll(int, int);
        // calculates max damage a character can inflict on another in a turn
        virtual int fight(Character*);
        // takes in incoming damage, and modifies it according to armor, defense and abilities
        virtual void damage(int dam);
        // get/set strength "hit points" for characters
        int getStrength();
        void setStrength(int);
        // get name
        virtual string getName() = 0;
        // heals character a random amount between 1 and total damage accumulated
        void heal();
};
#endif