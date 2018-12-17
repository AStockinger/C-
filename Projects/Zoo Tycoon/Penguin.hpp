/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Penguin specification, includes matching Animal
** constructors along with modified member vars 
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

const double PENGUIN_COST = 1000.00;
const double PEN_FOOD_COST_MULT = 1.0;
const double PENGUIN_PAYOFF_MULT = 0.1;

class Penguin : public Animal{
    public:
        // constructor
        Penguin();
};
#endif