#include "aoc_20xx_01.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_part_1(bool test) {
    std::ifstream input;
    std::cout << "Part_1 day 1" << std::endl;
    if (test) {
        input.open("../src/Template/test/test_1_1.txt");
        std::string answer;
        std::getline(input,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        input.open("../src/Template/input/day_1.txt");
    }
    std::string in;
    std::getline(input,in);
    std::cout << in << std::endl;
    input.close();
}

void run_part_2(bool test) {
    std::ifstream input;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        input.open("../src/Template//test/test_1_2.txt");
        std::string answer;
        std::getline(input,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        input.open("../src/Template/input/day_1.txt");
    }
    std::string in;
    std::getline(input,in);
    std::cout << in << std::endl;
    input.close();
}


void aoc_20xx_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_part_1(test);
    }
    if (part_2) {
        run_part_2(test);
    }
}