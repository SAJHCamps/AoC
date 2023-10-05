#include "aoc_2017_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>

void run_2017_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_2.txt");
    }
    std::string input;
    int sum = 0;
    while (std::getline(file,input)) {
        std::stringstream sinput(input);
        int current;
        int max = 0;
        int min = std::numeric_limits<int>::max();
        while(sinput >> current) {
            if (current > max) {
                max  = current;
            }
            if (current < min) {
                min = current;
            }
        }
        sum += max - min;
    }
    std::cout << sum << std::endl;
    file.close();
}

void run_2017_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_2.txt");
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


void aoc_2017_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2017_2_part_1(test);
    }
    if (part_2) {
        run_2017_2_part_2(test);
    }
}