#include <mergesort_outofplace.hpp>

std::vector<int>mergesort_outofplace(const std::vector<int>& array) {

    

}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {

    std::vector<int> merged_array(left.size() + right.size());

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged_array[i+j] = left[i];
            i = i + 1;
        }
        else {
            merged_array[i+j] = right[j];
            j = j + 1;
        }
    }
    while (i < left.size()) {
        merged_array[i+j] = left[i];
        i = i + 1;
    }
    while (j < right.size()) {
        merged_array[i+j] = right[j];
        j = j + 1;
    }

    return merged_array;

}
