#include "aoc_2015_01.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/Template/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/Template/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input << std::endl;
    file.close();
}

void run_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/Template/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/Template/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input << std::endl;
    file.close();
}


void aoc_2015_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_part_1(test);
    }
    if (part_2) {
        run_part_2(test);
    }
}