/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Space class specification
 ** manages color changes made by the ant
*********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

enum colorState {WHITE, BLACK};

class Space{
private:
	// represents current color of a Space
	colorState state;
public:
	// constructor is white space
	Space();
	// get and set Space color
	colorState getColor();
	void setColor(colorState);
};
#endif

