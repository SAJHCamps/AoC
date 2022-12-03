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

void run_2022_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_3.txt");
    }
    std::string input;
    int score = 0;
    while (std::getline(file,input)) {
        for (int i = 0; i < input.size()/2; i++) {
            if (input.find(input[i], input.size()/2) != std::string::npos) {
                if (input[i] >= char ('A') && input[i] <= char ('Z')) {
                    score += char (input[i]) - char ('A') + 27;
                    break;
                }
                else {
                    score += char (input[i]) - char ('a') + 1;
                    break;
                }
            }
        }
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2022_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_3.txt");
    }
    std::string input;
    std::vector<int> result;
    int score = 0;
    while (std::getline(file,input)) {
        switch (input[0]) {
            case 'A':
                switch (input[2]) {
                    case 'X':
                        score += 3;
                        break;
                    case 'Y':
                        score += 4;
                        break;
                    case 'Z':
                        score += 8;
                        break;
                    default:
                        break;
                }
                break;
            case 'B':
                switch (input[2]) {
                    case 'X':
                        score += 1;
                        break;
                    case 'Y':
                        score += 5;
                        break;
                    case 'Z':
                        score += 9;
                        break;
                    default:
                        break;
                }
                break;
            case 'C':
                switch (input[2]) {
                    case 'X':
                        score += 2;
                        break;
                    case 'Y':
                        score += 6;
                        break;
                    case 'Z':
                        score += 7;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    std::cout << score << std::endl;
    file.close();
}


void aoc_2022_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_3_part_1(test);
    }
    if (part_2) {
        run_2022_3_part_2(test);
    }
}