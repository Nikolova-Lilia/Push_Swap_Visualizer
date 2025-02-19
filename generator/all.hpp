#ifndef ALL_HPP
# define ALL_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> //For INT_MAX and INT_MIN
#include <sstream>
#include <cstdio>


int getValidInt(const std::string& prompt);
std::vector<int> generateNumbers(int nbr, int min, int max);

void    executeSortingProgram(const std::vector<int>& numbers);
void executePushSwap(const std::vector<int>& numbers);
#endif