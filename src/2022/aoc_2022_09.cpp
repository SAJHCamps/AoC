#include "aoc_2022_09.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

void run_2022_9_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 9" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_9_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_9.txt");
    }
    std::string input;
    int head[2] = {0,0};
    int tail[2] = {0,0};
    std::set<int> visited;
    visited.insert(tail[0]+ 18000*tail[1]);
    while (std::getline(file,input)) {
        int repeats = std::stoi(input.substr(2,std::string::npos));
        switch (input[0]) {
            case 'U':
                for (int i = 0; i < repeats; i++) {
                    head[0]++;
                    if (head[0] > tail[0]+1) {
                        tail[0]++;
                        if (head[1] != tail[1]) {
                            tail[1] = head[1];
                        }
                    }
                    visited.insert(tail[0]+ 18000*tail[1]);
                }
                break;
            case 'D':
                for (int i = 0; i < repeats; i++) {
                    head[0]--;
                    if (head[0] < tail[0]-1) {
                        tail[0]--;
                        if (head[1] != tail[1]) {
                            tail[1] = head[1];
                        }
                    }
                    visited.insert(tail[0]+ 18000*tail[1]);
                }
                break;
            case 'L':
                for (int i = 0; i < repeats; i++) {
                    head[1]--;
                    if (head[1] < tail[1]-1) {
                        tail[1]--;
                        if (head[0] != tail[0]) {
                            tail[0] = head[0];
                        }
                    }
                    visited.insert(tail[0]+ 18000*tail[1]);
                }
                break;
            case 'R':
                for (int i = 0; i < repeats; i++) {
                    head[1]++;
                    if (head[1] > tail[1]+1) {
                        tail[1]++;
                        if (head[0] != tail[0]) {
                            tail[0] = head[0];
                        }
                    }
                    visited.insert(tail[0]+ 18000*tail[1]);
                }
                break;
            default:
                break;
        }
    }

    std::cout << visited.size() << std::endl;
    file.close();
}

void run_2022_9_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 9" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_9_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_9.txt");
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
            }
            visited.insert(rope[18]+ 18000*rope[19]);
        }
    }

    std::cout << visited.size() << std::endl;
    file.close();
}


void aoc_2022_09(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_9_part_1(test);
    }
    if (part_2) {
        run_2022_9_part_2(test);
    }
}