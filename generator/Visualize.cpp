#include "all.hpp"

void visualizeSorting(std::vector<int> numbers, const std::vector<std::string>& operations) {
    std::vector<int> stackA = numbers;
    std::vector<int> stackB; // Empty stack B

    std::cout << "Initial state: " << std::endl;
    printStacks(stackA, stackB);

    for (const std::string& op : operations) {
        std::cout << "Operation: " << op;
        applyOperation(stackA, stackB, op);
        printStacks(stackA, stackB);
        sleep(1); // Pause for 1 second to see the step
    }

    std::cout << "Sorting complete!" << std::endl;
}

void applyOperation(std::vector<int>& stackA, std::vector<int>& stackB, std::string op) {
    if (op == "sa\n" && stackA.size() > 1) {
        std::swap(stackA[0], stackA[1]);
    }
    else if (op == "sb\n" && stackB.size() > 1) {
        std::swap(stackB[0], stackB[1]);
    }
    else if (op == "pa\n" && !stackB.empty()) {
        stackA.insert(stackA.begin(), stackB.front());
        stackB.erase(stackB.begin());
    }
    else if (op == "pb\n" && !stackA.empty()) {
        stackB.insert(stackB.begin(), stackA.front());
        stackA.erase(stackA.begin());
    }
    else if (op == "ra\n" && stackA.size() > 1) {
        stackA.push_back(stackA.front());
        stackA.erase(stackA.begin());
    }
    else if (op == "rb\n" && stackB.size() > 1) {
        stackB.push_back(stackB.front());
        stackB.erase(stackB.begin());
    }
    else if (op == "rr\n") {
        // Rotate both
        applyOperation(stackA, stackB, "ra\n");
        applyOperation(stackA, stackB, "rb\n");
    }
    else if (op == "rra\n" && stackA.size() > 1) {
        stackA.insert(stackA.begin(), stackA.back());
        stackA.pop_back();
    }
    else if (op == "rrb\n" && stackB.size() > 1) {
        stackB.insert(stackB.begin(), stackB.back());
        stackB.pop_back();
    }
    else if (op == "rrr\n") {
        // Reverse rotate both
        applyOperation(stackA, stackB, "rra\n");
        applyOperation(stackA, stackB, "rrb\n");
    }
}

void printStacks(const std::vector<int>& stackA, const std::vector<int>& stackB) {
    std::cout << "------------------" << std::endl;
    std::cout << "StackA      StackB" << std::endl;
    size_t maxSize = std::max(stackA.size(), stackB.size());

    for (size_t i = 0; i < maxSize; i++) {
        if (i < stackA.size()) std::cout << stackA[i] << "\t";
        else std::cout << "\t"; // Empty space for alignment

        if (i < stackB.size()) std::cout << stackB[i];

        std::cout << std::endl;
    }

    std::cout << "------------------" << std::endl;
}