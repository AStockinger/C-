/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Space class implementation
 ** keeps track of colors on board, including a color getter/setter
*********************************************************************************/

#include "Space.hpp"

// default space is white
Space::Space() {
	state = WHITE;
}

// get and set colorState
colorState Space::getColor() {
	return state;
}
void Space::setColor(colorState c) {
	state = c;
}