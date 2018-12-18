/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Exclusive Area specification
******************************************************************************/

#ifndef EXCLUSIVE_HPP
#define EXCLUSIVE_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

class Exclusive : public Space{
    private:
        bool win;
    public:
        Exclusive();
        virtual ~Exclusive();
        void interact(Player*);
        bool gameWon();
};
#endif