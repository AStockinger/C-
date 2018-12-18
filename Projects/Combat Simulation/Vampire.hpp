/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: Vampire class specification, includes special charm
** ability implementation
*********************************************************************/


#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character{
    public:
        Vampire();
        virtual ~Vampire();
        void damage(int);
        string getName();
};
#endif