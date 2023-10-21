#include "aoc_2020_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

void run_2020_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_2.txt");
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

void run_2020_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_2.txt");
    }
    std::string input;
    std::vector<int> numbers;
    while (std::getline(file,input)) {
        numbers.push_back(std::stoi(input));
    }
    int result;
    for (int i = 0; i<numbers.size() ;i++) {
        std::set<int> waiting;
        for (int j = i+1; j<numbers.size() ;j++) {
            if (waiting.find(2020- numbers[i] - numbers[j]) != waiting.end()) {
                result = numbers[i] * numbers[j] * (2020 - numbers[i] - numbers[j]);
                goto end;
            }
            else {
                waiting.insert(numbers[j]);
            }
        }
    }
end:
    std::cout << result << std::endl;
    file.close();
}


void aoc_2020_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2020_2_part_1(test);
    }
    if (part_2) {
        run_2020_2_part_2(test);
    }
}