/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Bar specification file, includes constructor and interact
 ** function to give player items/choices in the game
******************************************************************************/

#ifndef BAR_HPP
#define BAR_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

class Bar : public Space{
    private:
        bool hasKey;
        Item* key;
    public:
        Bar();
        virtual ~Bar();
        void interact(Player*);
        bool gameWon(){ return false;}
};
#endif