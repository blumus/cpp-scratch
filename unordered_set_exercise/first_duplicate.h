// first_duplicate.h
#pragma once

#include <optional>
#include <vector>

// Returns the first duplicate encountered while scanning left-to-right.
// If no duplicate exists, returns std::nullopt.
std::optional<int> find_first_duplicate(const std::vector<int>& nums);


