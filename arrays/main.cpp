#include <iostream>
#include <vector>

void print_int_array(const std::vector<int>& array) {

    for (const int& num : array) {
        std::cout << num;
        std::cout << "\t";
    }
    std::cout << std::endl;

}

void absolute_value_array(std::vector<int>& array) {

    for (int& num : array) {
        if (num < 0) {
            num = -1 * num;
        }
    }

}

int main () {

    // test print_int_array function
    // std::vector<int> array = {5,3,6};
    // print_int_array(array);

    // test absolute_value_array
    // std::vector<int> array = {-4, 5, 7, -2, 0};
    // print_int_array(array);
    // absolute_value_array(array);
    // print_int_array(array);

}
