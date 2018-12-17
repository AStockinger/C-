/*************************************************************************** 
** Program name: Lab 2 - letter fequencies in a txt file
** Author: Amy Stockinger
** Date: Sept 28, 2018
** Description: function reads the paragraph string from the input 
** file stream, then counts the letter frequencies of that paragraph, 
** and store the frequencies in the array. Disregards upper/lower 
** case letters.
***************************************************************************/
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;

#ifndef COUNTLETTERS_HPP
#define COUNTLETTERS_HPP

void count_letters(ifstream &, int*);

#endif