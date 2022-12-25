#include <hanoi.hpp>

#include <iostream>

int main() {

    Hanoi h(5);

    h.print_hanoi();

    h.solve_hanoi_recursively(5);

    h.print_hanoi();

}
