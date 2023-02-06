#include <hanoi.hpp>

#include <iostream>

int main() {

    Hanoi h(5);

    h.print_hanoi();

    h.solve(5);

    h.print_hanoi();

}
