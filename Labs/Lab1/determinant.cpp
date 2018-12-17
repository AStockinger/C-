/********************************************************************************
** Program Name: Matrix Calculator
** Author: Amy Stockinger
** Date: 9/20/18
** Description: returns determinant of a 2x2 or 3x3 matrix based on size
*********************************************************************************/

#include "determinant.hpp"

// calculates determinant according to standard formulas on website linked in module
int determinant(int size, int** matrix){
    if(size == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else{
        return (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])) -
        (matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])) +
        (matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]));
    }
}