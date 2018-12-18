/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Exclusive Invite specfication
******************************************************************************/

#ifndef EXCLUSIVEINVITE_HPP
#define EXCLUSIVEINVITE_HPP

#include "Item.hpp"

class ExclusiveInvite : public Item{
    public:
        ExclusiveInvite();
        virtual ~ExclusiveInvite();
        tag getTag();
        void message();
};
#endif