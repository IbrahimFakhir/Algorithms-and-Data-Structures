#pragma once

#include <iostream>
#include <vector>

class Student {

    public:
        void add_interest(std::string interest);
        void remove_interest(std::string interest);
        void remove_all_interests();
        void is_interest(std::string interest) const;

        void print_student() const;



    private:
        std::string first_name;
        std::string last_name;
        int birth_year;
        int birth_month;
        int birth_day;
        double height;
        std::vector<std::string> interests;

};
