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

        void solve_hanoi_recursively(int n, int source, int aux, int dest);

    private:
        // declare attributes
        std::vector<std::vector<size_t>> towers;

};
