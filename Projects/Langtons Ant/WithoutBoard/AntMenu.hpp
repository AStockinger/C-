/******************************************************************************
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Program name: Langton's Ant Menu
 ** Description: user menu specification for Langton's Ant simulation
******************************************************************************/

#ifndef ANTMENU_HPP
#define ANTMENU_HPP

#include "Ant.hpp"
#include "Space.hpp"

// main menu display has an intro blurb and asks user to start or quit
void menuDisplay();
// secondary menu gives user customization options to build and start the game
void menu(int);

#endif