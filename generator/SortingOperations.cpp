#include "all.hpp"

// Sorting Operations
// void pb(std::vector<int>& stackA, std::vector<int>& stackB) {
//     if (!stackA.empty()) {
//         stackB.push_back(stackA.back());
//         stackA.pop_back();
//     }
// }

// void pa(std::vector<int>& stackA, std::vector<int>& stackB) {
//     if (!stackB.empty()) {
//         stackA.push_back(stackB.back());
//         stackB.pop_back();
//     }
// }

// void sa(std::vector<int>& stackA) {
//     if (stackA.size() > 1) {
//         std::swap(stackA[stackA.size() - 1], stackA[stackA.size() - 2]);
//     }
// }

// void sb(std::vector<int>& stackB) {
//     if (stackB.size() > 1) {
//         std::swap(stackB[stackB.size() - 1], stackB[stackB.size() - 2]);
//     }
// }

// void ra(std::vector<int>& stackA) {
//     if (!stackA.empty()) {
//         int first = stackA.front();
//         stackA.erase(stackA.begin());
//         stackA.push_back(first);
//     }
// }

// void rb(std::vector<int>& stackB) {
//     if (!stackB.empty()) {
//         int first = stackB.front();
//         stackB.erase(stackB.begin());
//         stackB.push_back(first);
//     }
// }

// void rr(std::vector<int>& stackA, std::vector<int>& stackB) {
//     ra(stackA);
//     rb(stackB);
// }

// void rra(std::vector<int>& stackA) {
//     if (!stackA.empty()) {
//         int last = stackA.back();
//         stackA.pop_back();
//         stackA.insert(stackA.begin(), last);
//     }
// }

// void rrb(std::vector<int>& stackB) {
//     if (!stackB.empty()) {
//         int last = stackB.back();
//         stackB.pop_back();
//         stackB.insert(stackB.begin(), last);
//     }
// }

// void rrr(std::vector<int>& stackA, std::vector<int>& stackB) {
//     rra(stackA);
//     rrb(stackB);
// }

// Simulate sorting operations step by step
void simulateSorting(std::vector<int>& stackA, std::vector<int>& stackB, const std::vector<std::string>& operations, int minVal, int maxVal) {
    for (const std::string& op : operations) {
        system("clear"); // Clears screen before displaying the next state

        // Execute operation on stacks
        executeOperation(stackA, stackB, op);

        // Display the updated stack
        displayStack(stackA, stackB, minVal, maxVal);

        usleep(300000); // Delay for visualization (300ms)
    }
}

void executeOperation(std::vector<int>& stackA, std::vector<int>& stackB, const std::string& operation) {
    if (operation == "sa\n") {
        // Swap top 2 elements of stack A
        if (stackA.size() - 1) {
            std::swap(stackA[0], stackA[1]);
        }
    }
    else if (operation == "sb\n") {
        if (stackB.size() > 1)
            std::swap(stackB[0], stackB[1]);
    }
    else if (operation == "ss\n") {
        if (stackA.size() > 1)
            std::swap(stackA[0], stackA[1]);
        if (stackB.size() > 1)
            std::swap(stackB[0], stackB[1]);
    }
    else if (operation == "pa\n") {
        if (!stackB.empty()) {
            stackA.insert(stackA.begin(), stackB.front());
            stackB.erase(stackB.begin());
        }
    }
    else if (operation == "pb\n") {
        if (!stackA.empty()) {
            stackB.insert(stackB.begin(), stackA.front());
            stackA.erase(stackA.begin());
        }
    }
    else if (operation == "ra\n") {
        if (!stackA.empty()) {
            int first = stackA.front();
            stackA.erase(stackA.begin());
            stackA.push_back(first);
        }
    }
    else if (operation == "rb\n") {
        if (!stackB.empty()) {
            int first = stackB.front();
            stackB.erase(stackB.begin());
            stackB.push_back(first);
        }
    }
    else if (operation == "rr\n") {
        if (!stackA.empty()) {
            int firstA = stackA.front();
            stackA.erase(stackA.begin());
            stackA.push_back(firstA);
        }
        if (!stackB.empty()) {
            int firstB = stackB.front();
            stackB.erase(stackB.begin());
            stackB.push_back(firstB);
        }
    }
    else if (operation == "rra\n") {
        if (!stackA.empty()) {
            int last = stackA.back();
            stackA.pop_back();
            stackA.insert(stackA.begin(), last);
        }
    }
    else if (operation == "rrb\n") {
        if (!stackB.empty()) {
            int last = stackB.back();
            stackB.pop_back();
            stackB.insert(stackB.begin(), last);
        }
    }
    else if (operation == "rrr\n") {
        if (!stackA.empty()) {
            int lastA = stackA.back();
            stackA.pop_back();
            stackA.insert(stackA.begin(), lastA);
        }
        if (!stackB.empty()) {
            int lastB = stackB.back();
            stackB.pop_back();
            stackB.insert(stackB.begin(), lastB);
        }
    }
}

void displayStack(const std::vector<int>& stackA, const std::vector<int>& stackB, int minValue, int maxValue) {
    std::cout << "\n\033[1;33m---- STACK A ----    ----STACK B ----\033[0m\n";

    int maxSize = static_cast<int>(std::max(stackA.size(), stackB.size()));

    for (int i = 0; i < maxSize; i++) {
        if (i < static_cast<int>(stackA.size()))
            printColouredBlock(stackA[i], minValue, maxValue);
        // else {
        //     std::cout << "    \n"; // Empty space for alignment
        // }
        if (i < static_cast<int>(stackB.size())) {
            std::cout << "                        "; // Space between stacks
            printColouredBlock(stackB[i], minValue, maxValue);
        }
    }
}