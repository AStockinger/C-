/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Inventory implementation
******************************************************************************/

#include "Inventory.hpp"

// default inventory has no items
Inventory::Inventory(){
    numItems = 0;
}
Inventory::~Inventory(){
}

// add item to inventory if there is room
void Inventory::addItem(Item& item){
    if(numItems < limit){
        inventory.push_back(&item);
        numItems++;
    }
}

// returns an item if it is possessed
Item* Inventory::getItem(tag a){
    for(auto i : inventory){
        if(i->getTag() == a){
            return i;
        }
    }
    return NULL;
}

// checks for presence of specified item
bool Inventory::hasItem(tag a){
    if(numItems == 0){
        return false;
    }
    for(auto i : inventory){
        if(i->getTag() == a){
            return true;
        }
    }
    return false;
}