// Copyright Ion-Irinel Dinu 2022
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <vector>

#include "functions.h"
#include "person.h"

int main(void) {
    std::map<std::string, std::vector<Person>> family_map;

    read_input(family_map);

    create_output(family_map);

    return 0;
}

// run test -> make
