/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Exclusive Invite implementation, including a tag identifier
 ** and a message for when the player recieves this item
******************************************************************************/

#include "ExclusiveInvite.hpp"
#include <iostream>
using std::cout;
using std::endl;

ExclusiveInvite::ExclusiveInvite(){
    name = EXCLUINV;
}

ExclusiveInvite::~ExclusiveInvite(){
}

tag ExclusiveInvite::getTag(){
    return name;
}

void ExclusiveInvite::message(){
        cout << "A casino employee congratulates your winnings and hands you a small, fancy envelope." << endl;
        cout << "You open it to find an invite to the Exclusive Players Area, as indicated by '?\?\?\' on the map." << endl;
}