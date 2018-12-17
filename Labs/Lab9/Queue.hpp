/******************************************************************************
 ** Program name: Lab 9
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: a class that implements std::queue using the push and pop
 ** functions while pushing/popping numbers according to RNG vs user-chosen
 ** percentages, and keeping track of the length and average length of the queue
******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>
using std::queue;

class Queue{
    private:
        queue<int> buffer;          // the queue
        int length;                 // current queue length
        double avgLength;           // keeps track of average length across rounds
    public:
        Queue();
        // function takes in user-chosen numbers to generate rounds based on their percentages
        void simulation(int rounds, int percentageAdd, int percentageRemove);
};

#endif