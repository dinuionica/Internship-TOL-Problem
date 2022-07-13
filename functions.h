#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

#include "person.h"

// The structure that contains the comparator function used
// to sort people  according to age depending on the day, month and year
struct sort_by_date {
    bool operator()(const Person& first_person, const Person& second_person) {
        if (first_person.year_date != first_person.year_date) {
            return first_person.year_date < second_person.year_date;
        }

        if (first_person.month_date != second_person.month_date) {
            return first_person.month_date < second_person.month_date;
        }
        return first_person.day_date < second_person.day_date;
    }
};

// The function  that takes over the input, creates the hashmap and
// applies a sorting according to age
void read_input(std::map<std::string, std::vector<Person>>& family_map) {
    int number_persons;
    std::cin >> number_persons;
    for (int i = 0; i < number_persons; ++i) {
        // take input
        std::string first_name;
        std::string last_name;
        std::string date;
        std::cin >> first_name;
        std::cin >> last_name;
        std::cin >> date;

        // create a new person
        int persons_year = stoi(date.substr(0, 4));
        int persons_month = stoi(date.substr(5, 7));
        int persons_day = stoi(date.substr(8, 10));
        Person new_person(first_name, last_name, persons_year, persons_month,
                          persons_day);

        // add in map and sort the vector of persons by age
        family_map[last_name].push_back(new_person);
        std::sort(family_map[last_name].begin(), family_map[last_name].end(),
                  sort_by_date());
    }
}

// The function that creates output
void create_output(std::map<std::string, std::vector<Person>>& family_map) {
    // I chose to copy the data from the map to a pair vector so that I could
    // sort the vectors by size because the map doesn't have this sort operation
    std::vector<std::pair<std::string, std::vector<Person>>> temp_vector;

    // copy every element from map to vector
    for (const auto& item : family_map) {
        temp_vector.push_back(item);
    }

    // sort by size using the second element of pair
    std::sort(temp_vector.begin(), temp_vector.end(),
              [](const auto& first_item, const auto& secont_item) {
                  return first_item.second.size() > secont_item.second.size();
              });

    // display the result
    for (const auto& [key, value] : temp_vector) {
        std::cout << key << " : ";
        for (auto it = value.begin(); it != value.end(); ++it) {
            std::cout << it->first_name << " ";
        }
        std::cout << "\n";
    }
}

#endif  // FUNCTIONS_H