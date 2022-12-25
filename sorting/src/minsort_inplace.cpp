#include <minsort_inplace.hpp>

void minsort_inplace(std::vector<int>& array) {

    int swap_index;
    int tmp;

    for (int i = 0; i < array.size(); i++) {
        swap_index = i;
        for (int j = i; j < array.size(); j++) {      
            if (array[j] < array[swap_index]) {
                swap_index = j;
            }
        }
        tmp = array[i];
        array[i] = array[swap_index];
        array[swap_index] = tmp;
    }

}
