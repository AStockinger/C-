/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Space class implementation
*********************************************************************************/

#include "Space.hpp"

// default space is white and does not contain ant
Space::Space() {
	state = WHITE;
	ant = false;
}

// get and set colorState
colorState Space::getColor() {
	return state;
}
void Space::setColor(colorState c) {
	state = c;
}

// get and set ant on a space with a bool marker      
bool Space::getAnt() {
	return ant;
}     
void Space::setAnt(bool a) {
	ant = a;
}