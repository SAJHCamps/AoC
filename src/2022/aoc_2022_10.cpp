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
#include <algorithm>

void run_2022_10_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 10" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_10_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_10.txt");
    }
    std::string input;
    int score = 0;
    int X = 1;
    int cycles = 1;
    while (std::getline(file, input)) {
        switch (input[0]) {
            case 'n':
                if ((cycles - 20) % 40 == 0) {
                    score += X*cycles;
                }
                cycles++;
                break;
            case 'a':
                if ((cycles - 20) % 40 == 0 && cycles >= 20) {
                    score += X*cycles;
                }
                cycles ++;
                if ((cycles - 20) % 40 == 0 && cycles >= 20) {
                    score += X*cycles;
                }
                cycles ++;
                X += std::stoi(input.substr(5, std::string::npos));
                break;
            default:
                break;
        }
    }

    std::cout << score << std::endl;
    file.close();
}

void run_2022_10_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 10" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_10_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_10.txt");
    }
    std::string input;
    int rope[20] = {0};
    std::set<int> visited;
    visited.insert(rope[18]+ 18000*rope[19]);
    while (std::getline(file,input)) {
        int repeats = std::stoi(input.substr(2,std::string::npos));
        for (int i = 0; i< repeats; i++) {
            switch (input[0]) {
                case 'U':
                    rope[0]++;
                    break;
                case 'D':
                    rope[0]--;
                    break;
                case 'L':
                    rope[1]--;
                    break;
                case 'R':
                    rope[1]++;
                    break;
                default:
                    break;
            }
            for (int j = 1; j <10; j++) {
                if (rope[2*(j-1)] > rope[2*j] + 1) {
                    rope[2*j]++;
                    if (rope[2*(j-1)+1] > rope[2*j + 1]) {
                        rope[2*j+1]++;
                    }
                    else if (rope[2*(j-1)+1] < rope[2*j + 1]) {
                        rope[2*j+1]--;
                    }
                }
                else if (rope[2*(j-1)] < rope[2*j] - 1) {
                    rope[2*j]--;
                    if (rope[2*(j-1)+1] > rope[2*j + 1]) {
                        rope[2*j+1]++;
                    }
                    else if (rope[2*(j-1)+1] < rope[2*j + 1]) {
                        rope[2*j+1]--;
                    }
                }
                else if (rope[2*(j-1)+1] < rope[2*j+1] - 1) {
                    rope[2*j+1]--;
                    if (rope[2*(j-1)] > rope[2*j]) {
                        rope[2*j]++;
                    }
                    else if (rope[2*(j-1)] < rope[2*j]) {
                        rope[2*j]--;
                    }
                }
                else if (rope[2*(j-1)+1] > rope[2*j+1] + 1) {
                    rope[2*j+1]++;
                    if (rope[2*(j-1)] > rope[2*j]) {
                        rope[2*j]++;
                    }
                    else if (rope[2*(j-1)] < rope[2*j]) {
                        rope[2*j]--;
                    }
                }
            };
            visited.insert(rope[18]+ 18000*rope[19]);
        }
    }

    std::cout << visited.size() << std::endl;
    file.close();
}


void aoc_2022_10(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_10_part_1(test);
    }
    if (part_2) {
        run_2022_10_part_2(test);
    }
}