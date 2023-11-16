#include "aoc_2020_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <utility>

void run_2020_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_3.txt");
    }
    std::string input;
    int count = 0;
    int x = 0;
    std::getline(file, input);
    int size = input.length();
    if (input[x] == '#')
        count++;
    x = (x+3)%size;
    while (std::getline(file, input)) {
        if (input[x] == '#')
            count++;
        x = (x+3)%size;
    }
    std::cout << count << std::endl;
    file.close();
}

void run_2020_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_3.txt");
    }
    std::string input;
    int y = 1;
    std::pair<int,int> directions[5] = {{1,1}, {3,1}, {5,1}, {7,1}, {1,2}};
    long count[5] = {0,0,0,0,0};
    int x[5] = {0,0,0,0,0};
    std::getline(file, input);
    int size = input.length();
    for (int i = 0; i < 5; i++) {
        if (input[x[i]] == '#')
            count[i]++;
        x[i] = (x[i]+directions[i].first)%size;
    }
    while (std::getline(file, input)) {
        for (int i = 0; i < 5; i++) {
            if (y % directions[i].second == 0) {
                if (input[x[i]] == '#')
                    count[i]++;
                x[i] = (x[i]+directions[i].first)%size;
            }
        }
        y++;
    }
    std::cout << count[0] * count[1] * count[2] * count[3] * count[4] << std::endl;
    file.close();
}


void aoc_2020_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2020_3_part_1(test);
    }
    if (part_2) {
        run_2020_3_part_2(test);
    }
}