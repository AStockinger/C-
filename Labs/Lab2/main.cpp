/*************************************************************************** 
** Program name: Lab 2 - letter fequencies in a txt file
** Author: Amy Stockinger
** Date: Sept 28, 2018
** Description: main function for program that combines functions to 
** take an input txt file and output files for lower case letter counts
** of each paragraph in the file
***************************************************************************/

#include "CountLetters.hpp"
#include "OutputLetters.hpp"

using std::cout;
using std::endl;

int main(){
    // file input object
    ifstream inputFile;

    // make int array of size 26 of 0's to represent each letter and their count
    int charArray[26];

    // welcome user and get input file name
    cout << "Give me a file, and I'll count the letter frequencies for each paragraph," <<
    "and place each of those in new files." << endl;

    // count input file letters
    count_letters(inputFile, charArray);

    return 0;
}
