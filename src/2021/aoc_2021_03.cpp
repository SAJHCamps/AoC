#include "aoc_2021_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <queue>

void run_2021_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_3.txt");
    }
    std::string input;
    int depth = 0;
    int dist = 0;
    while (std::getline(file,input)) {
        int amount = std::stoi(input.substr(input.find_first_of("0123456789")));
        switch (input[0]) {
            case 'f':
                dist += amount;
                break;
            case 'd':
                depth += amount;
                break;
            case 'u':
                depth -= amount;
                break;
            default:
                break;
        }
    }
    std::cout << depth * dist << std::endl;
    file.close();
}

void run_2021_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_3.txt");
    }
    std::string input;
    int angle = 0;
    int depth = 0;
    int dist = 0;
    while (std::getline(file,input)) {
        int amount = std::stoi(input.substr(input.find_first_of("0123456789")));
        switch (input[0]) {
            case 'f':
                dist += amount;
                depth += angle*amount;
                break;
            case 'd':
                angle += amount;
                break;
            case 'u':
                angle -= amount;
                break;
            default:
                break;
        }
    }
    std::cout << depth * dist << std::endl;
    file.close();
}


void aoc_2021_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2021_3_part_1(test);
    }
    if (part_2) {
        run_2021_3_part_2(test);
    }
}