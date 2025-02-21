#include "all.hpp"

int main() {
    srand(time(0)); //Seed random number generator

    // Get user input with validation
    int nbr = getValidInt("Enter number of elements to generate: ");
    int min = getValidInt("Enter the minimum value: ");
    int max = getValidInt("Enter the maximum value: ");

    //Ensure min is not greater than max
    if (min > max) {
        std::cerr << "Error: Min value cannot be greater than Max value. Please re-enter.\n";
        min = getValidInt("Enter the minimum value: ");
        max = getValidInt("Enter the maximum value: ");
    }

    // Generate numbers
    std::vector<int> numbers = generateNumbers(nbr, min, max);
    std::vector<std::string> operations; // Declare operations vector 

    // Print the generated numbers
    std::cout << "Generated numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Pass numbers to the sorting program
    executePushSwap(numbers, operations);
        // Call visualization function
    visualizeSorting(numbers, operations, min, max);

    return (0);
}