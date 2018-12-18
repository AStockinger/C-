/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Inventory specification
******************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"
#include <vector>
using std::vector;

class Inventory{
    private:
        vector<Item*> inventory;
        int numItems;
        int limit = 3;
    public:
        Inventory();
        ~Inventory();
        void addItem(Item&);
        Item* getItem(tag);
        void removeItem(int index);
        bool hasItem(tag);
};
#endif