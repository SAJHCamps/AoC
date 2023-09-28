#include "aoc_2020_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>

void run_2020_1_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_1.txt");
    }
    std::string input;
    std::set<int> waiting;
    int result;
    while (std::getline(file,input)) {
        int current = std::stoi(input);
        if (waiting.find(2020- current) != waiting.end()) {
            result = current * (2020 - current);
            break;
        }
        else {
            waiting.insert(current);
        }
    }
    std::cout << result << std::endl;
    file.close();
}

void run_2020_1_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_1_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input << std::endl;
    file.close();
}


void aoc_2020_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2020_1_part_1(test);
    }
    if (part_2) {
        run_2020_1_part_2(test);
    }
}