#include <minsort_outofplace.hpp>

#include <iostream>

int main() {

    std::vector<int> unsorted = {7, 10, 5, 5, 8, 2};
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
