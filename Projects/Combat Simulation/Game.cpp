/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18 
** Description: Game function implementation
** takes two fighters and has them fight to determine a winner
*********************************************************************/

#include <iostream>
#include "Game.hpp"
#include "InputVal.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
using std::cout;
using std::endl;

void selectCharacters(){
    int choice;

    Character* fighter1;
    Character* fighter2;
    fighter1 = nullptr;
    fighter2 = nullptr;

    // have user pick two fighters
    cout << "Please choose two characters to battle each other:" << endl
    << "1. The Barbarian" << endl
    << "2. The Blue Men" << endl
    << "3. Harry Potter" << endl
    << "4. Medusa" << endl
    << "5. The Vampire" << endl;

    cout << "Enter fighter 1: ";
    getInt(choice, 1, 5);

    switch(choice){
        case 1: fighter1 = new Barbarian;
            break;
        case 2: fighter1 = new BlueMen;
            break;
        case 3: fighter1 = new HarryPotter;
            break;
        case 4: fighter1 = new Medusa;
            break;
        case 5: fighter1 = new Vampire;
            break;
    }

    cout << "Enter fighter 2: ";
    getInt(choice, 1, 5);

    switch(choice){
        case 1: fighter2 = new Barbarian;
            break;
        case 2: fighter2 = new BlueMen;
            break;
        case 3: fighter2 = new HarryPotter;
            break;
        case 4: fighter2 = new Medusa;
            break;
        case 5: fighter2 = new Vampire;
            break;
    }

    game(fighter1, fighter2);

    // prevent leaks
    delete fighter1;
    delete fighter2;
}

void game(Character *fighterA, Character *fighterB){
    bool gamePlay = true;

    while(gamePlay == true){
        // fighter A goes first
        fighterA->damage(fighterB->fight(fighterA));
        // check status if a player "dies"
        if(fighterA->getStrength() <= 0 && fighterB->getStrength() > 0){
            cout << "Fighter 2 wins!" << endl;
            gamePlay = false;
            break;
        }
        else if(fighterA->getStrength() > 0 && fighterB->getStrength() <= 0){
            cout << "Fighter 1 wins!" << endl;
            gamePlay = false;
            break;
        }
        else if(fighterA->getStrength() <= 0 && fighterB->getStrength() <= 0){
            cout << "It's a tie game!" << endl;
            gamePlay = false;
            break;
        }

        // then fighter B moves
        fighterB->damage(fighterA->fight(fighterB));
        // check status again
        if(fighterA->getStrength() <= 0 && fighterB->getStrength() > 0){
            cout << "Fighter 2 wins!" << endl;
            gamePlay = false;
            break;
        }
        else if(fighterA->getStrength() > 0 && fighterB->getStrength() <= 0){
            cout << "Fighter 1 wins!" << endl;
            gamePlay = false;
            break;
        }
        else if(fighterA->getStrength() <= 0 && fighterB->getStrength() <= 0){
            cout << "It's a tie game!" << endl;
            gamePlay = false;
            break;
        }
        // loop until someone "dies"
    }
    cout << endl;
}