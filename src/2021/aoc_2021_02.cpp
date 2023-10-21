#include "aoc_2021_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <queue>

void run_2021_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_2.txt");
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

void run_2021_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_2.txt");
    }
    std::string input;
    int count = 0;
    std::queue<int> q;
    std::getline(file,input);
    q.push(stoi(input));
    std::getline(file,input);
    q.push(stoi(input));
    std::getline(file,input);
    q.push(stoi(input));
    while (std::getline(file,input)) {
        int current = stoi(input);
        int previous = q.front();
        if (current > previous) {
            count++;
        }
        q.push(current);
        q.pop();
    }
    std::cout << count << std::endl;
    file.close();
}


void aoc_2021_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2021_2_part_1(test);
    }
    if (part_2) {
        run_2021_2_part_2(test);
    }
}