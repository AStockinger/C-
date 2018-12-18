/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Player class specification
******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Inventory.hpp"
#include "Space.hpp"
#include <string>

using std::string;

class Player{
    private:
        // player to set their name
        string name;
        // character's items
        Inventory* inventory;
        // player's total money, 
        int money;
        // player's current location
        Space* current;
    public:
        // initiaize player witb name and position
        Player(string);
        ~Player();
        // name getter
        string getName();
        // get inventory
        Inventory* getInventory();
        // get/set money
        int getMoney();
        void setMoney(int);
        Space* getCurrentSpace();
        void setCurrentSpace(Space*);
};
#endif