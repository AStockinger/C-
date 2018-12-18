/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Medusa class specification, includes special glare
** ability implementation
*********************************************************************/


#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character{
    public:
        Medusa();
        virtual ~Medusa();
        int fight(Character*);
        string getName();
};
#endif