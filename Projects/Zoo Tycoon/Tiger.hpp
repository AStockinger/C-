/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Tiger specification, includes matching Animal
** constructors along with modified member vars 
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

const double TIGER_COST = 10000.00;
const double TIGER_FOOD_COST_MULT = 5.0;
const double TIGER_PAYOFF_MULT = 0.2;

class Tiger: public Animal{
    public:
        // constructor
        Tiger();
};
#endif