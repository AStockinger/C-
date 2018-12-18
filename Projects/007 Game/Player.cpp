/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Player class implementation
******************************************************************************/

#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

Player::Player(string a){
    name = a;
    money = 100000;
    current = NULL;
    inventory = new Inventory();
}

Player::~Player(){
    delete inventory;
}

string Player::getName(){
    return name;
}

Inventory* Player::getInventory(){
    return inventory;
}

int Player::getMoney(){
    return money;
}
void Player::setMoney(int a){
    money = a;
}

Space* Player::getCurrentSpace(){
    return current;
}
        
void Player::setCurrentSpace(Space* s){
    if(s != NULL){
        current = s;
    }
}