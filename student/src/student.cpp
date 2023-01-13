#include <student.hpp>

Student::Student(
        size_t student_id,
        std::string first_name,
        std::string last_name,
        int birth_year,
        int birth_month,
        int birth_day,
        double height,
        std::vector<std::string> interests) {
    
    this->student_id = student_id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->birth_year = birth_year;
    this->birth_month = birth_month;
    this->birth_day = birth_day;
    this->height = height;
    this->interests = interests;

}

bool Student::operator<(const Student& other) const {

    return this->student_id < other.get_student_id();

}
bool Student::operator>(const Student& other) const {

    return this->student_id > other.get_student_id();

}
bool Student::operator==(const Student& other) const {

    return this->student_id == other.get_student_id();

}
bool Student::operator!=(const Student& other) const {

    return this->student_id != other.get_student_id();

}

void Student::add_interest(std::string interest) {
    
    this->interests.push_back(interest);

}
void Student::remove_interest(std::string interest) {

    for (size_t i = 0; i < interests.size(); i++) {
        if (interests[i] == interest) {
            interests.erase(interests.begin() + i);
        }
    }

}
void Student::remove_all_interests() {

    interests.clear();

}
bool Student::is_interest(std::string interest) const {

    for (int i = 0; i < interests.size(); i++) {
        if (interest == interests[i]) {
            return true;
        }
    }
    return false;

}

void Student::print_student() const {

    std::cout << "first name:\t" << first_name << std::endl;
    std::cout << "last name:\t" << last_name << std::endl;
    std::cout << "date of birth:\t" << birth_day << '.' << birth_month << '.' << birth_year << std::endl;
    std::cout << "height:\t\t" << height << " cm" << std::endl;
    std::cout << "interests:\t" << std::endl;
    for (const std::string& interest : interests) {
        std::cout << "\t- " << interest << std::endl;
    }

}

size_t Student::get_student_id() const {

    return student_id;

}
std::string Student::get_first_name() const {

    return first_name;

}
void Student::set_first_name(std::string first_name) {

    this->first_name = first_name;

}
std::string Student::get_last_name() const {

    return last_name;

}
void Student::set_last_name(std::string last_name) {

    this->last_name = last_name;

}
int Student::get_birth_year() const {

    return birth_year;

}
void Student::set_birth_year(int birth_year) {

    this->birth_year = birth_year;

}
int Student::get_birth_month() const {

    return birth_month;

}
void Student::set_birth_month(int birth_month) {

    this->birth_month = birth_month;

}
int Student::get_birth_day() const {

    return birth_day;

}
void Student::set_birth_day(int birth_day) {

    this->birth_day = birth_day;

}
double Student::get_height() const {

    return height;

}
void Student::set_height(double height) {

    this->height = height;

}
std::vector<std::string> Student::get_interests() const {

    return interests;

}
