#include <student.hpp>

#include <iostream>
#include <algorithm>
#include <set>
#include <map>

typedef std::set<Student, StudentCmp> StudentSet;
typedef std::map<Student, StudentSet, StudentCmp> CanteenMap;

int main() {

    /*Student s1("Eren", "Akdag", 27, 7, 2002, 178);
    Student s2("Margaret ", "Akdag", 24, 4, 1959, 162);
    Student s3("Amy", "Roberts", 4, 6, 1954, 171);
    Student s4("Lucas", "Dahmer", 28, 9, 2001, 165);
    Student s5("Anna", "Todd", 21, 9, 1989, 155);
    Student s6("Jeromy", "Lewis", 15, 4, 1952, 165);
    Student s7("Mark", "Anderson", 13, 9, 1964, 183);
    Student s8("Karen", "White", 1, 7, 2001, 166);
    Student s9("Jamal", "Maron", 29, 3, 1999, 196);
    Student s10("Kevin", "Gaton", 19, 11, 1967, 182);
    Student s11("Zion", "Builder", 14, 5, 1989, 175);
    Student s12("Kathrin", "Blank", 5, 12, 2004, 177);
    Student s13("Jaquavis", "Light", 21, 10, 2002, 203);
    Student s14("Bril", "Long", 15, 7, 2003, 154);
    Student s15("Giannes", "Kump", 3, 2, 1985, 191);
    Student s16("Marcel", "Pois", 6, 5, 1992, 189);
    std::vector<Student> students = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16};

    // sort by first_name
    std::cout << "--------------------------------" << std::endl;
    std::cout << "sorted by first name:" << "\n\n";
    std::sort(students.begin(), students.end(), [](Student s1, Student s2){return s1.get_first_name() < s2.get_first_name();});
    for (const Student& s : students) {
        std::cout << s.get_first_name() << std::endl;
    }*/

    
    Student alex(111, "Alex", "Akdag", 2003, 12, 15, 178);
    Student tobi(222, "Tobi", "Akdag", 2003, 12, 15, 178);
    Student pascal(333, "Pascal", "Akdag", 2003, 12, 15, 178);
    Student lisa(444, "Lisa", "Akdag", 2003, 12, 15, 178);
    Student frauke(555, "Frauke", "Akdag", 2003, 12, 15, 178);
    Student fatma(666, "Fatma", "Akdag", 2003, 12, 15, 178);
    
    StudentSet alex_pref;
    alex_pref.insert(tobi);
    alex_pref.insert(pascal);
    alex_pref.insert(lisa);

    StudentSet frauke_pref;
    frauke_pref.insert(tobi);
    frauke_pref.insert(alex);
    frauke_pref.insert(fatma);

    StudentSet lisa_pref;
    lisa_pref.insert(frauke);
    lisa_pref.insert(alex);

    CanteenMap preferences;
    // inserting keys implicitly
    preferences[alex] = alex_pref;
    preferences[frauke] = frauke_pref;
    preferences[lisa] = lisa_pref;
    
    // demo
    for (const auto& key: preferences) {
        std::cout << "Key: \t| " << key.first.get_first_name() << " |\nValue:\t| ";
        for (const auto& value: key.second) {
            std::cout << value.get_first_name() << " | ";
        }
        std::cout << std::endl << std::endl;
    }

}
