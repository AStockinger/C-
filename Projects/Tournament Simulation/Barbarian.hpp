/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Barbarian class specification, inherits Character
** straightforward class with no special abilities
*********************************************************************/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character{
    public:
        Barbarian();
        virtual ~Barbarian();
        string getName();
};
#endif