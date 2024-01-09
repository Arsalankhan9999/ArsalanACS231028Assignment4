#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

int main() {
    // Initialize a vector with 100,000 integers in descending order
    std::vector<int> numbers(100000);
    for (int i = 0; i < 100000; ++i) {
        numbers[i] = 100000 - i;
    }

    // Measure execution time for Bubble Sort
    auto bubbleStartTime = std::chrono::high_resolution_clock::now();
    // Bubble Sort
    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int j = 0; j < numbers.size() - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    auto bubbleEndTime = std::chrono::high_resolution_clock::now();
    auto bubbleDuration = std::chrono::duration_cast<std::chrono::microseconds>(bubbleEndTime - bubbleStartTime);

    // Measure execution time for STL sort
    auto stlStartTime = std::chrono::high_resolution_clock::now();
    std::sort(numbers.begin(), numbers.end());
    auto stlEndTime = std::chrono::high_resolution_clock::now();
    auto stlDuration = std::chrono::duration_cast<std::chrono::microseconds>(stlEndTime - stlStartTime);

    // Print execution times
    std::cout << "Bubble Sort Execution Time: " << bubbleDuration.count() << " microseconds\n";
    std::cout << "STL Sort Execution Time: " << stlDuration.count() << " microseconds\n";

    // Print first 10 and last 10 integers to verify sorting
    std::cout << "First 10 integers: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\nLast 10 integers: ";
    for (int i = numbers.size() - 10; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

