/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Stair Key item specification
******************************************************************************/

#ifndef STAIRKEY_HPP
#define STAIRKEY_HPP

#include "Item.hpp"

class StairKey : public Item{
    public:
        StairKey();
        virtual ~StairKey();
        tag getTag();
        void message();
};
#endif