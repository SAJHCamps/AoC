#include "aoc_2015_01.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    int sum = 0;
    for (auto &ch: input ) {
        if (ch == '(') {
            sum++;
        }
        else if (ch == ')') {
            sum--;
        }
        else {
            sum = -1000;
        }
    }
    std::cout << sum << std::endl;
    file.close();
}

void run_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    int sum = 0;
    int count = 0;
    for (auto &ch: input ) {
        count++;
        if (ch == '(') {
            sum++;
        }
        else if (ch == ')') {
            sum--;
        }
        else {
            sum = -1000;
        }

        if (sum == -1) {
            std::cout << count << std::endl;
            break;
        }
    }
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