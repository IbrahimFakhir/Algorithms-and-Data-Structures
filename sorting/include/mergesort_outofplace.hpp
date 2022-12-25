#pragma once

#include <vector>

std::vector<int> mergesort_outofplace(const std::vector<int>& array);

std::vector<int> __merge(const std::vector<int>& links, const std::vector<int>& rechts);
