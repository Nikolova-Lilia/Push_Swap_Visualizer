#ifndef ALL_HPP
# define ALL_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> //For INT_MAX and INT_MIN
#include <sstream>
#include <cstdio> // For popen()
#include <unistd.h> // For sleep()


int getValidInt(const std::string& prompt);
std::vector<int> generateNumbers(int nbr, int min, int max);

void    executeSortingProgram(const std::vector<int>& numbers);
void executePushSwap(const std::vector<int>& numbers);

void visualizeSorting(std::vector<int> numbers, const std::vector<std::string>& operations);
void applyOperation(std::vector<int>& stackA, std::vector<int>& stackB, std::string op);
void printStacks(const std::vector<int>& stackA, const std::vector<int>& stackB);


#endif