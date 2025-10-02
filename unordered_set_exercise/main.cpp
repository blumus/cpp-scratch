#include "first_duplicate.h"
#include <iostream>
#include <cassert>
#include <optional>
#include <vector>
#include <string>
#include <cstdlib>

// Helper function to run a single test case
void run_test(const std::vector<int>& input, std::optional<int> expected, const std::string& name) {
    std::optional<int> result = find_first_duplicate(input);

    std::cout << "Running test: " << name << " ... ";

    // Compare and report helpful diagnostics instead of assert-only.
    if (result != expected) {
        std::cout << "FAILED. expected="
                  << (expected ? std::to_string(*expected) : std::string("null"))
                  << " got="
                  << (result ? std::to_string(*result) : std::string("null"))
                  << std::endl;
        std::exit(1);
    }

    std::cout << "PASSED!" << std::endl;
}

int main() {
    // --- Test Case 1: Standard Case (Duplicate in the middle) ---
    run_test({1, 5, 2, 4, 5, 3}, 5, "Standard Duplicate (5)");

    // --- Test Case 2: No Duplicates ---
    run_test({1, 2, 3, 4, 5}, std::nullopt, "No Duplicates");

    // --- Test Case 3: Multiple Duplicates (Ensure we get the first one) ---
    // 9 is the first duplicate encountered (at index 3). 8 is the second (at index 5).
    run_test({9, 8, 7, 9, 6, 8}, 9, "Multiple Duplicates (Expected 9)");

    // --- Test Case 4: Duplicate is the first element ---
    run_test({10, 20, 30, 10, 40}, 10, "First Element Duplicate (10)");

    // --- Test Case 5: Empty Vector ---
    run_test({}, std::nullopt, "Empty Vector");

    // --- Test Case 6: Consecutive Duplicates ---
    run_test({1, 2, 2, 3, 4}, 2, "Consecutive Duplicates (2)");

    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}