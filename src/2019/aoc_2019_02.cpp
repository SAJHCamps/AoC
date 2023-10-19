#include "aoc_2019_02.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_2019_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_2.txt");
    }
    std::string input;
    int sum = 0;
    while (getline(file,input)) {
        sum += std::stoi(input)/3 - 2;
    }
    std::cout << sum << std::endl;
    file.close();
}

void run_2019_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_2.txt");
    }
    std::string input;
    int sum = 0;
    while (getline(file,input)) {
        int unchecked = std::stoi(input)/3 - 2;
        while (unchecked > 0) {
            sum += unchecked;
            unchecked = unchecked / 3 - 2;
        }
    }
    std::cout << sum << std::endl;
    file.close();
}


void aoc_2019_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2019_2_part_1(test);
    }
    if (part_2) {
        run_2019_2_part_2(test);
    }
}