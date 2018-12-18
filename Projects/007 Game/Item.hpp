/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: abstract base class for items
******************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

enum tag {KEY, COMMDEV, EXCLUINV};

class Item{
    protected:
        tag name;
    public:
        Item();
        virtual ~Item();
        virtual tag getTag() = 0;
        virtual void message() = 0;
};
#endif