/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Roulette specification
******************************************************************************/

#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include "Space.hpp"

class Roulette : public Space{
    public:
        Roulette();
        virtual ~Roulette();
        void interact(Player*);
        void bet(Player*, int, int, int, int);
        bool gameWon(){ return false;}
};
#endif