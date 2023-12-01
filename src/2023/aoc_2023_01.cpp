#include "aoc_2023_01.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_2023_1_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_1.txt");
    }
    std::string input;
    int score = 0;
    while(std::getline(file,input)) {
        int first = input.find_first_of("0123456789");
        int last = input.find_first_of("0123456789", first+1);
        int second_last = first;
        while (last != std::string::npos) {
            second_last = last;
            last = input.find_first_of("0123456789", last+1);
        }
        score += 10*(input[first]- '0') + input[second_last] - '0';
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2023_1_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_1_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_1.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input << std::endl;
    file.close();
}


void aoc_2023_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_1_part_1(test);
    }
    if (part_2) {
        run_2023_1_part_2(test);
    }
}