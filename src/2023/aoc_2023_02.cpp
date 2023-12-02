#include "aoc_2023_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run_2023_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_2.txt");
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

void run_2023_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_2.txt");
    }
    std::string input;
    std::string input_parsed;
    int score = 0;
    std::vector<std::string> literals = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while(std::getline(file,input)) {
        input_parsed = input;
        for (int i = 0; i <= 8; i++) {
            int index = input.find(literals[i]);
            while (index != std::string::npos) {
                input_parsed.replace(index, 1, std::to_string(i+1));
                index = input.find(literals[i], index+1);
            }
        }
        int first = input_parsed.find_first_of("0123456789");
        int last = input_parsed.find_first_of("0123456789", first+1);
        int second_last = first;
        while (last != std::string::npos) {
            second_last = last;
            last = input_parsed.find_first_of("0123456789", last+1);
        }
        score += 10*(input_parsed[first]- '0') + input_parsed[second_last] - '0';
    }
    std::cout << score << std::endl;
    file.close();
}


void aoc_2023_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_2_part_1(test);
    }
    if (part_2) {
        run_2023_2_part_2(test);
    }
}