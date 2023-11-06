#include "aoc_2019_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <climits>

void run_2019_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_3.txt");
    }
    std::vector<int> program;
    std::string input;
    std::set<std::pair<int,int>> seen;
    std::getline(file, input);
    int current = 0;
    int x = 0;
    int y = 0;
    while (true) {
        char direction = input[current];
        int start = input.find_first_of("0123456789",current);
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        for (int i = 0; i < amount; i++) {
            switch (direction) {
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'D':
                    y--;
                    break;
                default:
                    std::cout << "I have a bad feeling about this" << std::endl;
            }
            seen.insert({x,y});
        }
        if (end > 0)
            current = end+1;
        else
            break;
    }
    std::getline(file, input);
    current = 0;
    x = 0;
    y = 0;
    int minimum = INT_MAX;
    while (true) {
        char direction = input[current];
        int start = input.find_first_of("0123456789",current);
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        for (int i = 0; i < amount; i++) {
            switch (direction) {
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'D':
                    y--;
                    break;
                default:
                    std::cout << "I have a bad feeling about this" << std::endl;
            }
            if (std::abs(x)+std::abs(y) <= minimum && seen.find({x,y}) != seen.end()) {
                minimum = std::abs(x)+std::abs(y);
            }
        }
        if (end > 0)
            current = end+1;
        else
            break;
    }
    std::cout << minimum << std::endl;
    file.close();
}

void run_2019_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 3 day 1" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_3.txt");
    }
    std::vector<int> program;
    std::string  input;

    file.close();
}


void aoc_2019_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2019_3_part_1(test);
    }
    if (part_2) {
        run_2019_3_part_2(test);
    }
}