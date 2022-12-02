#include "aoc_2022_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <unordered_set>
#include <tuple>
#include <openssl/md5.h>
#include <bits/stdc++.h>

void run_2022_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_2.txt");
    }
    std::string input;
    int max = 0;
    int current = 0;
    while (std::getline(file,input)) {
        if (input.empty()) {
            if (current > max) {
                max = current;
            }
            current = 0;
        }
        else {
            current += stoi(input);
        }
    }
    std::cout << max << std::endl;
    file.close();
}

void run_2022_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_2.txt");
    }
    std::string input;
    std::vector<int> result;
    int current = 0;
    while (std::getline(file,input)) {
        if (input.empty()) {
            result.push_back(current);
            current = 0;
        }
        else {
            current += stoi(input);
        }
    }
    std::sort(result.begin(), result.end(),std::greater<int>());
    std::cout << result[0]+result[1]+result[2] << std::endl;
    file.close();
}


void aoc_2022_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_2_part_1(test);
    }
    if (part_2) {
        run_2022_2_part_2(test);
    }
}