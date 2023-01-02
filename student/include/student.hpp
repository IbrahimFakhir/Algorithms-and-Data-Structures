#pragma once

#include <iostream>
#include <vector>

class Student {

    public:
        Student(
            std::string first_name,
            std::string last_name,
            int birth_year,
            int birth_month,
            int birth_day,
            double height
        );
        
        void add_interest(std::string interest);
        void remove_interest(std::string interest);
        void remove_all_interests();
        void is_interest(std::string interest) const;

        void print_student() const;

        // getter and setter functions
        std::string get_first_name() const;
        void set_first_name(std::string first_name);
        std::string get_last_name() const;
        void set_last_name(std::string last_name);
        std::string get_full_name() const;

        int get_birth_year() const;
        void set_birth_year(int birth_year);
        int get_birth_month() const;
        void set_birth_month(int birth_month);
        int get_birth_day() const;
        void set_birth_day(int birth_day);
        int get_date_of_birth() const;

        double get_height() const;
        void set_height(int height);
        
        std::string get_interests() const;

    private:
        std::string first_name;
        std::string last_name;
        int birth_year;
        int birth_month;
        int birth_day;
        double height;
        std::vector<std::string> interests;

};
