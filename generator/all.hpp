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

// ANSI colour codes
# define RESET "\033[0m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[38;5;208m"
# define RED "\033[31m"
# define WHITE "\033[37m"

// RandNumbGen.cpp
int getValidInt(const std::string& prompt);
std::vector<int> generateNumbers(int nbr, int min, int max);
void executePushSwap(const std::vector<int>& numbers, std::vector<std::string>& operations);

void visualizeSorting(std::vector<int> numbers, const std::vector<std::string>& operations, int minVal, int maxVal);
// void applyOperation(std::vector<int>& stackA, std::vector<int>& stackB, std::string op);
// void printStacks(const std::vector<int>& stackA, const std::vector<int>& stackB);

std::string getColour(int num, int minVal, int maxVal);
void displayStacks(const std::vector<int>& stackA, const std::vector<int>& stackB, int minVal, int maxVal);

void pb(std::vector<int>& stackA, std::vector<int>& stackB);
void pa(std::vector<int>& stackA, std::vector<int>& stackB);
void sa(std::vector<int>& stackA);
void sb(std::vector<int>& stackB);
void ra(std::vector<int>& stackA);
void rb(std::vector<int>& stackB);
void rr(std::vector<int>& stackA, std::vector<int>& stackB);
void rra(std::vector<int>& stackA);
void rrb(std::vector<int>& stackB);
void rrr(std::vector<int>& stackA, std::vector<int>& stackB);
void simulateSorting(std::vector<int>& stackA, std::vector<int>& stackB, int minVal, int maxVal);

#endif