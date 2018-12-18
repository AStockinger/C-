/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: CommDevice specification class includes an extra function
 ** to give clues to the player.
******************************************************************************/

#ifndef COMMDEVICE_HPP
#define COMMDEVICE_HPP

#include "Item.hpp"

class CommDevice : public Item{
    public:
        CommDevice();
        virtual ~CommDevice();
        tag getTag();
        void message();
};
#endif