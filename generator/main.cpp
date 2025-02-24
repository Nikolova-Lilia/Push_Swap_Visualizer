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

    // Pass numbers to the sorting program
    executePushSwap(numbers, operations);
        // Call visualization function
    visualizeSorting(numbers, operations, min, max);

    std::cout << "Sorting Completed!" << std::endl;

    // Print the input in the end
    std::cout << "Number of elements that were generated: "
    << nbr << std::endl;
    std::cout << "MIN value to start from: " << min << std::endl;
    std::cout << "MAX value to end to: " << max << std::endl;

    // Print the generated numbers
    std::cout << "Generated numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Print the number of operations needed to sort the numbers
    size_t numOperations = operations.size();
    std::cout << "Number of Operations needed for sorting the numbers: "
    << numOperations << std::endl;

    return (0);
}