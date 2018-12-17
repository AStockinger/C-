/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Space class specification for Langton's Ant Simulator
 ** To manage the board space colors and where the ant is, the board will
 ** be made using an array of Spaces
*********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

enum colorState {WHITE, BLACK};

class Space{
private:
	// represents current color of a Space
	colorState state;
	// true when ant exists on a Space, false if not
	bool ant;
public:
	Space();
	// get and set Space color
	colorState getColor();
	void setColor(colorState);
	// get and set ant on Space
	bool getAnt();
	void setAnt(bool);
};
#endif

