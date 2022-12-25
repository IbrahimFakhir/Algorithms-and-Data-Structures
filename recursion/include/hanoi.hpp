#pragma once

#include <vector>
#include <cstddef>
#include <iostream>

class Hanoi {

    public:
        // declare constructor
        Hanoi(size_t num_of_plates);
        // declare memeber functions
        bool is_move_valid(size_t from, size_t to);
        void move(size_t from, size_t to);

        void print_hanoi();

        void solve_hanoi_recursively(
            int from_tower = 0, 
            int help_tower = 1, 
            int to_tower = 2);

    private:
        // declare attributes
        std::vector<std::vector<size_t>> towers;

};
