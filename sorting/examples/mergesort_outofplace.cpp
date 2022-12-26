#include <mergesort_outofplace.hpp>

#include <iostream>

void print_int_array(const std::vector<int>& array) {

    for (const int& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}

int main() {

    std::vector<int> a = {-3, 9, 32, 7};
    std::vector<int> b = mergesort_outofplace(a);
    print_int_array(b);

}
