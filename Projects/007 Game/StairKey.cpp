/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Stair Key item implementation
******************************************************************************/

#include "StairKey.hpp"

StairKey::StairKey(){
    name = KEY;
}

StairKey::~StairKey(){

}

tag StairKey::getTag(){
    return name;
}

void StairKey::message(){
    
}