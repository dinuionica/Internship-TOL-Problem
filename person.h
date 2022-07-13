#ifndef PERSON_H
#define PERSON_H
#include <string>

// A person's specific class
class Person {
   public:
    std::string first_name;
    std::string last_name;
    int year_date;
    int month_date;
    int day_date;

    // the constructor of the class
    Person(std::string first_name, std::string last_name, int year_date,
           int month_date, int day_date) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->year_date = year_date;
        this->month_date = month_date;
        this->day_date = day_date;
    }
};

#endif  // PERSON_H