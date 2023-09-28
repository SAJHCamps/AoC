#include "aoc_2021_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

void run_2021_1_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_1.txt");
    }
    std::string input;
    int count = 0;
    int previous = INT_MAX;
    while (std::getline(file,input)) {
        int current = stoi(input);
        if (current > previous) {
            count++;
        }
        previous = current;
    }
    std::cout << count << std::endl;
    file.close();
}

void run_2021_1_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_1_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input << std::endl;
    file.close();
}


void aoc_2021_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2021_1_part_1(test);
    }
    if (part_2) {
        run_2021_1_part_2(test);
    }
}