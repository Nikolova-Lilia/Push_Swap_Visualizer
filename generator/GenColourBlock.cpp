#include "all.hpp"

// // Function to get colour based on number
// std::string getColour(int num, int minVal, int maxVal) {
//     if (num < 0) {
//         return (num < minVal / 2) ? BLUE : CYAN;
//     }
//     else if (num == 0) {
//         return WHITE;
//     }
//     else {
//         return (num > maxVal / 2) ? RED : ORANGE;
//     }
// }

// // Function to display the stacks visually
// void displayStacks(const std::vector<int>& stackA, const std::vector<int>& stackB, int minVal, int maxVal) {
//     system("clear"); // Clear terminal for updated visualization

//     std::cout << "StackA: " << std:: endl;
//     for (int num : stackA) {
//         std::string colour = getColour(num, minVal, maxVal);
//         int barSize = (num - minVal) * 10 / (maxVal - minVal) + 1;
//         std::cout << colour;
//         for (int i = 0; i < barSize; i++) std::cout << "█";
//         std::cout << RESET << " " << num << std::endl;
//     } 

//     std::cout << "\nStack B: " << std::endl;
//     for (int num : stackB) {
//         std::string colour = getColour(num, minVal, maxVal);
//         int barSize = (num - minVal) * 10 / (maxVal - minVal) + 1;
//         std::cout << colour;
//         for (int i = 0; i < barSize; i++) std::cout << "█";
//         std::cout << RESET << " " << num << std::endl;
//     }
//     usleep(300000); // Slow down execution to visualize movement
// }

void printColouredBlock(int num, int minValue, int maxValue) {
    int range = maxValue - minValue;
    int normalized = (num - minValue) * 255 / range;

    int red = 255 - normalized; // Red decreases as number increases
    int green = normalized;       // Green increases as number increases
    int blue = 128;              // Keep a stable blue for contrast

    std::cout << "\033[38;2;" << red << ";" << green << ";"
        << blue << "m" << num << "\033[0m";
}