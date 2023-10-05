#include "aoc_2021_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <queue>

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
    int previous = std::numeric_limits<int>::max();
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


void aoc_2021_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2021_1_part_1(test);
    }
    if (part_2) {
        run_2021_1_part_2(test);
    }
}