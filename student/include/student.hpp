#pragma once

#include <iostream>
#include <vector>
#include <cstddef>

class Student {

    public:
        // @param interests defaults as an empty array
        Student(
            size_t student_id,
            std::string first_name,
            std::string last_name,
            int birth_year,
            int birth_month,
            int birth_day,
            double height,
            std::vector<std::string> interests = {}
        );

        bool operator<(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator==(const Student& other) const;
        bool operator!=(const Student& other) const;
        
        void add_interest(std::string interest);
        void remove_interest(std::string interest);
        void remove_all_interests();
        bool is_interest(std::string interest) const;

        void print_student() const;

        size_t get_student_id() const;
        std::string get_first_name() const;
        void set_first_name(std::string first_name);
        std::string get_last_name() const;
        void set_last_name(std::string last_name);
        int get_birth_year() const;
        void set_birth_year(int birth_year);
        int get_birth_month() const;
        void set_birth_month(int birth_month);
        int get_birth_day() const;
        void set_birth_day(int birth_day);
        double get_height() const;
        void set_height(double height);
        std::vector<std::string> get_interests() const;

    private:
        size_t student_id;
        std::string first_name;
        std::string last_name;
        int birth_year;
        int birth_month;
        int birth_day;
        double height;
        std::vector<std::string> interests;

};

class StudentCmp {

    public:
        bool operator() (const Student& x, const Student& y) const {
            return x < y;
        }

};
