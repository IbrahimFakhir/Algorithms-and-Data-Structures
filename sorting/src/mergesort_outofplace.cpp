#include <mergesort_outofplace.hpp>

std::vector<int>mergesort_outofplace(const std::vector<int>& array) {

    if (array.size() == 1) {
        return array;
    }

    int mid = ceil(array.size() / 2.0);

    std::vector<int> left = mergesort_outofplace(std::vector<int>{array.begin(), array.end() - mid});
    std::vector<int> right = mergesort_outofplace(std::vector<int>{array.begin() + mid - (array.size() % 2), array.end()});

    return merge(left, right);

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
