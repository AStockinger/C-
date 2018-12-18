/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Roof specification file, gives player an item after player
 ** accomplishes a task
******************************************************************************/

#ifndef ROOF_HPP
#define ROOF_HPP

#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"

class Roof : public Space{
    private:
        // bool determines what happens when player is on this space
        bool guard;
        //  pointer to item given from space
        Item* device;
    public:
        // constructor and destructor
        Roof();
        virtual ~Roof();
        // interact with player via fight scene
        void interact(Player*);
        // to get and set bool after scene has been cleared
        void setGuard(bool);
        bool getGuard();
        bool gameWon(){ return false;}
};
#endif