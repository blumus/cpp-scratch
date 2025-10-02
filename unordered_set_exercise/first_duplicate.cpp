// Implement here
#include "first_duplicate.h"
#include <unordered_set>

// Returns the first duplicate encountered while scanning left-to-right.
// If no duplicate exists, returns std::nullopt.
std::optional<int> find_first_duplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    seen.reserve(nums.size());
    for (const int value : nums) {
        if (seen.count(value)) {
            return value; // C++20: seen.contains(value)
        }
        seen.insert(value);
    }
    return std::nullopt;
}

