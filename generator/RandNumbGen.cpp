#include "all.hpp"
/*  Using vertor:   A vector is a sequence container that can store a collection of
    elements dynamically. It is Resizable - No need to define size in advance. 
    Easy element insertion & deletion(compared to raw arrays). Can store any data
    type (integers, strings, custom objects, etc.)
    Why using std::vector here? - Because we don't know in advance how many numbers
    will be generated. Dynamically will be allocated storage based on user input. 
    New numbers will be append using push_back(). Avoids raw memory management.*/

    /*  Range-Based Loop    for(int num : numbers) {
                            std::cout << num << " ";
                            }
        It's used to iterate over each element in a collection(like a vector) easily.
        It literally means: for each element in numbers/the collection, assign it to num.
        It automatically iterates through the whole vector.
        No need to use an index(i) manually.

        It is equivalent of traditional for loop:
        for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        std::cout << num << " ";
        }
*/

/*      push_back() is a function used to add elements to the end of the vector.
        example:
                std::vector<int> numbers;
                numbers.push_back(10); // Adds 10 to the vector
                numbers.push_back(20); // Adds 20
                Now, numbers = {10, 20}; */
// Function to generate random numbers in a given range
std::vector<int> generateNumbers(int nbr, int min, int max) {
    std::vector<int> numbers;
    for (int i = 0; i < nbr; i++) {
        numbers.push_back(rand() % (max - min + 1) + min);
    }

    // Print the generated numbers
    std::cout << "Generated Numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return (numbers);
}

// Function to safely get an integer from user input
int getValidInt(const std::string& prompt) {
    int value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        //check for invalid input (non-integer)
        if (std::cin.fail()) {
            std::cin.clear(); //clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //Discard invalid input
            std::cout << "Invalid input! Please enter an integer.\n";
            continue;
        }
        
        // Check if within valid integer range
        if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
            std::cout << "Error: Value out of range. Please enter a valid integer.\n";
            continue;
        }

        return (value); // Valid input
    }
}

void executePushSwap(const std::vector<int>& numbers, std::vector<std::string>& operations) {
    // Convert vector of numbers into a space-separated string
    std::ostringstream oss;
    for (size_t i = 0; i < numbers.size(); i++) {
        oss << numbers[i];
        if (i != numbers.size() - 1) oss << " ";
        // Add space between numbers
    }

    std::string command = "../push_swap/push_swap \"" + oss.str() + "\"";
    // Path to push_swap program
    std::cout << "Executing command: " << command << std::endl;

    //Open a process to read push_swap output
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error: Failed to run push_swap!" << std::endl;
        return ;
    }

    // Read Operations from push_swap output
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        operations.push_back(buffer); // Store operations in the passed reference
    }
    pclose(pipe);
}