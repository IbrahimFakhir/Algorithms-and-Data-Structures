#include <mergesort_outofplace.hpp>

std::vector<int> mergesort_outofplace(const std::vector<int>& array) {

    if (array.size() == 1) {
        return array;
    }

    int mid = ceil(array.size() / 2.0);
    std::vector<int> left (&array[0], &array[mid]);
    std::vector<int> right (&array[mid], &array[array.size()]);

    left = mergesort_outofplace(left);
    right = mergesort_outofplace(right);

    return merge(left, right);

}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {

    std::vector<int> merged(left.size() + right.size());

    int i,j = 0;

    while (i < left.size() && i < right.size()) {
        if (left[i] < right[j]) {
            merged[i+j] = left[i];
            i++;
        }
        else {
            merged[i+j] = right[j];
            j++;
        }
    }
    while (i < left.size()) {
        merged[i+j] = left[i];
        i++;
    }
    while (j < right.size()) {
        merged[i+j] = right[j];
        j++;
    }

    return merged;

}
