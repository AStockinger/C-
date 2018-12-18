/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: CommDevice implementation class includes an extra function
 ** to give clues to the player.
******************************************************************************/

#include "CommDevice.hpp"
#include <iostream>

using std::cout;
using std::endl;

CommDevice::CommDevice(){
    name = COMMDEV;
}

CommDevice::~CommDevice(){

}

tag CommDevice::getTag(){
    return name;
}

void CommDevice::message(){
    cout << "You hear a static sound, and then a voice on the device 'Look for more high rollers to" << endl <<
    "give out invites. The boss is getting bored.'" << endl;
}