/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Card implementation uses integers to represent the faces,
 ** suits and values of a card
******************************************************************************/


#include "Card.hpp"
#include <iostream>

using std::cout;

Card::Card(){

}

Card::Card(int f, int s){
    face = f;
    suit =  s;

    switch(face){
        case 0: value = 2;
        break;
        case 1: value = 3;
        break;
        case 2: value = 4;
        break;
        case 3: value = 5;
        break;
        case 4: value = 6;
        break;
        case 5: value = 7;
        break;
        case 6: value = 8;
        break;
        case 7: value = 9;
        break;
        case 8: value = 10;
        break;
        case 9: value = 10;
        break;
        case 10: value = 10;
        break;
        case 11: value = 10;
        break;
        case 12: value = 11;
        break;
    }
}

int Card::getValue(){
    return value;
}

void Card::printCard(){
    switch(face){
        case 0: cout << "Two";
        break;
        case 1: cout << "Three";
        break;
        case 2: cout << "Four";
        break;
        case 3: cout << "Five";
        break;
        case 4: cout << "Six";
        break;
        case 5: cout << "Seven";
        break;
        case 6: cout << "Eight";
        break;
        case 7: cout << "Nine";
        break;
        case 8: cout << "Ten";
        break;
        case 9: cout << "Jack";
        break;
        case 10: cout << "Queen";
        break;
        case 11: cout << "King";
        break;
        case 12: cout << "Ace";
        break;
    }
    switch(suit){
        case 0: cout << " of Spades";
        break;
        case 1: cout << " of Hearts";
        break;
        case 2: cout << " of Clubs";
        break;
        case 3: cout << " of Diamonds";
        break;
    }
}