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

void run_2022_6_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 6" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_6_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_6.txt");
    }
    std::string input;
    std::getline(file, input);
    int found;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != input[i+1] && input[i] != input[i+2] && input[i] != input[i+3] && input[i+1] != input[i+2] && input[i+1] != input[i+3] && input[i+2] != input[i+3]) {
            found = i + 4;
            break;
        }
    }
    std::cout << found << std::endl;
    file.close();
}

void run_2022_6_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 6" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_6_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_6.txt");
    }
    std::string input;
    int score = 0;
    int count = 0;
    std::set<char> total_intersection;
    while (std::getline(file,input)) {
        std::string second_line;
        std::string third_line;
        std::getline(file, second_line);
        std::getline(file, third_line);
        for (auto ch: input) {
            if (second_line.find(ch) != std::string::npos && third_line.find(ch) != std::string::npos) {
                if (ch >= char ('A') && ch <= char ('Z')) {
                    score += ch - char ('A') + 27;
                    break;
                }
                else {
                    score += ch - char ('a') + 1;
                    break;
                }
            }
        }
    }
    std::cout << score << std::endl;
    file.close();
}


void aoc_2022_06(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_6_part_1(test);
    }
    if (part_2) {
        run_2022_6_part_2(test);
    }
}