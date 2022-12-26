#include <mergesort_outofplace.hpp>

#include <iostream>

void print_int_array(const std::vector<int>& array) {

    for (const int& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}

int main() {

    std::vector<int> a = {17, -3, 9, 32, 7};
    std::cout << "unsorted array: " << std::endl;
    print_int_array(a);

    a = mergesort_outofplace(a);
    std::cout << "sorted array: " << std::endl;
    print_int_array(a);

}
