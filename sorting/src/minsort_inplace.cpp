#include <minsort_inplace.hpp>

std::vector<int> minsort_inplace(std::vector<int> array) {

    for (int i = 0; i < array.size(); i++) {
        int swap_index = i;
        for (int j = i; j < array.size(); j++) {      
            if (array[j] < array[swap_index]) {
                swap_index = j;
            }
        }
        int tmp = array[i];
        array[i] = array[swap_index];
        array[swap_index] = tmp;
    }

    return array;

}
