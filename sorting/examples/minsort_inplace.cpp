#include <minsort_inplace.hpp>
#include <iostream>
#include <vector>
#include <iomanip>

void print_array(const std::vector<int>& array) {
  for(const int& num: array) {
    std::cout << std::setw(5) << num;
  }
  std::cout << std::endl;
}

int main() {

	std::vector<int> array = {5, 6, -32, 2, 0, 5};
    minsort_inplace(array);

}
