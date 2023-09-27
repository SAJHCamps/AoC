#include "aoc_2017_01.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_2017_1_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    int sum = 0;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] == input[(i+1)%len]){
            sum += input[i] - '0';
        }
    }
    std::cout << sum << std::endl;
    file.close();
}

void run_2017_1_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_1_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    int sum = 0;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] == input[(i+len/2)%len]){
            sum += input[i] - '0';
        }
    }
    std::cout << sum << std::endl;
    file.close();
}


void aoc_2017_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2017_1_part_1(test);
    }
    if (part_2) {
        run_2017_1_part_2(test);
    }
}