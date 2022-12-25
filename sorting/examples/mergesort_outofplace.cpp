#include <mergesort_outofplace.hpp>

#include <iostream>

void print_int_array(const std::vector<int>& array) {

    for (const int& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}

int main() {

    std::vector<int> a = {1, 3, 6, 6};
    std::vector<int> b = {2, 4, 4, 7, 9, 10};
    std::vector<int> c = merge(a, b);

    print_int_array(c);

}
