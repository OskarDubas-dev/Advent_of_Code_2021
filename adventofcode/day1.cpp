﻿/*
*Day 1
 *To do this, count the number of times a depth measurement increases from the previous measurement.
 *(There is no measurement before the first measurement.)
 *How many measurements are larger than the previous measurement?
 *
 *
 *--- Part Two ---
*
Your goal now is to count the number of times the sum of measurements in this sliding window increases from the previous sum.
So, compare A with B, then compare B with C, then C with D, and so on.
Stop when there aren't enough measurements left to create a new three-measurement sum.
 */


#include "day1.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


day1::day1()
{
    vector<int> inputArray; //day1, input array, all integers from the file
    vector<int> threeInputArray; //day2, sum of 3 integers
    int line;

    //getting input from the file to both vector arrays
    ifstream file("input.txt");
    if (file.is_open())
    {
        while (file >> line)
        {
            inputArray.push_back(line);
        }
        for (int i = 0; i < inputArray.size(); i++)
        {
            if (i >= 2)
            {
                threeInputArray.push_back(inputArray[i] + inputArray[i - 1] + inputArray[i - 2]);
            }
        }
    }
    file.close();

    cout << checkArray(inputArray) << endl;
    cout << checkArray(threeInputArray) << endl;
}

int day1::checkArray(std::vector<int> array)
{
    int counter = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (i > 0)
        {
            if (array[i] > array[i - 1]) counter++;
        }
    }
    return counter;
}
