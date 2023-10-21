#include "aoc_2017_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

void run_2017_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_3.txt");
    }
    int target;
    file >> target;
    int rank = 1;
    while (rank*rank < target) {
        rank += 2;
    }
    int steps = (rank*rank - target)%(rank -1);
    std::cout << rank/2 + std::abs(steps - rank/2)<< std::endl;
    file.close();
}

void run_2017_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_3.txt");
    }
    std::string input;
    int sum = 0;
    while (std::getline(file,input)) {
        std::stringstream sinput(input);
        int current;
        std::vector<int> numbers;
        while(sinput >> current) {
            numbers.push_back(current);
        }
        for (int i: numbers) {
            for (int j: numbers) {
                if (i%j == 0 && i != j) {
                    sum += i/j;
                    goto brk;
                }
            }
        }
        brk:
    }
    std::cout << sum << std::endl;
    file.close();
}


void aoc_2017_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2017_3_part_1(test);
    }
    if (part_2) {
        run_2017_3_part_2(test);
    }
}