#include <all.hpp>

/*  We have two ways to pass numbers:
    1. ./a.out 1 2 3 4 (separate arguments)
    2. ./a.out "1 2 3 4" (single argument with spaces)*/

// Function to pass numbers to the C sorting program as a single argument
void    executeSortingProgram(const std::vector<int>& numbers) {
    std::ostringstream cmdStream;
    cmdStream << "./push_swap \"";

    for (size_t i = 0; i < numbers.size(); i++) {
        cmdStream << numbers[i];
        if (i < numbers.size() - 1) {
            cmdStream << " "; // Add spaces between numbers
        }
    }

    cmdStream << "\""; //Close the quoted argument

    std::string command = cmdStream.str();
    std::cout << "Executing: " << command << "\n"; //Show the command being run

    //Open a pipe to capture output from the sorting program
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error: Failed to run sorting program.\n";
        return ;
    }

    // Read and display output from the C program
    char buffer[128];
    while(fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }

    pclose(pipe);
}