#include <minsort_outofplace.hpp>

#include <iostream>

int main() {

    std::vector<int> unsorted = {5, 2, 7, 8, 1};
    for (int& num : unsorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> sorted = minsort_outofplace(unsorted);
    for (int& num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}
