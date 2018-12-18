/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Slots specification. Player can play slot games to win money.
 ** Also, there is potential to interact with special items to progress in the
 ** game.
******************************************************************************/

#ifndef SLOTS_HPP
#define SLOTS_HPP

#include <string>
#include "Space.hpp"
#include "Player.hpp"
#include "Item.hpp"
using std::string;

class Slots : public Space{
    private:
        // player may pick up a key item here
        Item* invite;
    public:
        Slots();
        virtual ~Slots();
        // player can play slot games
        void interact(Player*);
        // converts int to slot symbol
        string slotSymbol(int);
        bool gameWon(){ return false;}
};
#endif