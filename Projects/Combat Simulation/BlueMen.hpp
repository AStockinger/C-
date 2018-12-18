/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: BlueMen class specification
** includes mob ability that will decrease defense dice each time 1/3
** of strength is lost
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character{
    public:
        BlueMen();
        virtual ~BlueMen();
        void damage(int);
        // get and set dice
        void setDefDice(int);
        int getDefDice();
        string getName();
};
#endif