#include <hanoi.hpp>

// define constructor
Hanoi::Hanoi(size_t num_of_plates) {
    
    towers = std::vector<std::vector<size_t>>(3);

    for (size_t i = num_of_plates; i > 0; i--) {
        towers[0].push_back(i);
    }

}
// define member functions
bool Hanoi::is_move_valid(size_t from, size_t to) {

    return !towers[from].empty() && !towers[to].empty();

}
void Hanoi::move(size_t from, size_t to) {

    std::vector<size_t>& from_tower = towers[from];
    std::vector<size_t>& to_tower = towers[to];

    to_tower.push_back(from_tower.back());
    from_tower.pop_back();

}

void Hanoi::print_hanoi() {

    std::cout << std::endl;
    for (size_t i = 0; i < 3; i++) {
        std::cout << "Tower " << i << ": ";
        for (size_t j = 0; j < towers[i].size(); j++) {
            std::cout << towers[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void Hanoi::solve_hanoi_recursively(int n, int from_tower, int help_tower, int to_tower) {

    if (n == 1) {
        move(from_tower, to_tower);
        return;
    }

    solve_hanoi_recursively(n-1, from_tower, to_tower, help_tower);
    move(from_tower, to_tower);
    solve_hanoi_recursively(n-1, help_tower, from_tower, to_tower);

}
