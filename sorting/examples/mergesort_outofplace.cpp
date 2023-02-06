#include <mergesort_outofplace.hpp>

#include <iostream>
#include <iomanip>

void print_array(const std::vector<int>& array) {
  for(const int& num: array) {
    std::cout << std::setw(5) << num;
  }
  std::cout << std::endl;
}

int main() {

    std::vector<int> a = {17, -3, 9, 32, 32, 7, 6};
    print_array(a);

    a = mergesort_outofplace(a);
    print_array(a);

}
