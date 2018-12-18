/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Blackjack specification file, includes constructor and interact
 ** function to give player items/choices in the game
******************************************************************************/

#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "Space.hpp"
#include "Item.hpp"

class Blackjack : public Space{
    private:
        Item* invite;
    public:
        Blackjack();
        virtual ~Blackjack();
        void interact(Player*);
        bool gameWon(){ return false;}
};
#endif