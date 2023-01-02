#include <student.hpp>

#include <iostream>

void print_string_array(const std::vector<std::string>& array) {

    for (const std::string& str : array) {
        std::cout << str << std::endl;
    }

}

int main() {

    Student s = Student("a", "b", 2, 3, 4, 2.0, {"gg", "asd"});

    s.print_student();

}
