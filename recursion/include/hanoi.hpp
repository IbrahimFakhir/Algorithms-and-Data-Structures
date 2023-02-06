#pragma once

#include <vector>
#include <cstddef>
#include <iostream>

class Hanoi {

    public:
        Hanoi(size_t num_of_plates);

        bool is_move_valid(size_t from, size_t to);
        void move(size_t from, size_t to);

        void print_hanoi();

        void solve_hanoi_recursively(int n, int from_tower = 0, int help_tower = 1, int to_tower = 2);

    private:
        std::vector<std::vector<size_t>> towers;

};
