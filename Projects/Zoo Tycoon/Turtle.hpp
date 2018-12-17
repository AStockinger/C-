/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Turtle specification, includes matching Animal
** constructors along with modified member vars 
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

const double TURTLE_COST = 100.00;
const double TURTLE_FOOD_COST_MULT = 0.5;
const double TURTLE_PAYOFF_MULT = 0.05;

class Turtle : public Animal{
    public:
        // constructor
        Turtle();
};
#endif