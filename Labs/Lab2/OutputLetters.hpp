/*************************************************************************** 
** Program name: Lab 2
** Author: Amy Stockinger
** Date: Sept 28, 2018
** Description: asks user for the filename the user would like to output to, 
** then outputs the frequencies of letters to the output file in the format 
** specified above
***************************************************************************/
#include <fstream>
#include <iostream>
#include <string>

using std::ofstream;

#ifndef OUTPUTLETTERS_HPP
#define OUTPUTLETTERS_HPP

void output_letters(ofstream &, int*);

#endif