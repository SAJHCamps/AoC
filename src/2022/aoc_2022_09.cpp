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
                    };
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
                    };
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
                    };
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
                    };
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
    std::vector<std::vector<int>> forest;
    std::vector<std::vector<bool>> spotted;

    while (std::getline(file, input)) {
        std::vector<int> current_line;
        for (auto &ch: input) {
            current_line.push_back(ch - '0');
        }
        forest.push_back(current_line);
    }
    for (int i = 0; i < forest.size(); i++) {
        std::vector<bool> current_line;
        for (int j = 0; j < forest.size(); j++) {
            current_line.push_back(false);
        }
        spotted.push_back(current_line);
    }

    int score = 0;
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest.size(); j++) {
            int current_score = 1;
            int visible_sum = 0;
            for (int k = i+1; k < forest.size(); k++) {
                visible_sum++;
                if (forest[i][j] <= forest[k][j]){
                    break;
                }
            }
            current_score *= visible_sum;
            visible_sum = 0;
            for (int k = j+1; k < forest.size(); k++) {
                visible_sum++;
                if (forest[i][j] <= forest[i][k]){
                    break;
                }
            }
            current_score *= visible_sum;
            visible_sum = 0;
            for (int k = i-1; k >= 0; k--) {
                visible_sum++;
                if (forest[i][j] <= forest[k][j]){
                    break;
                }
            }
            current_score *= visible_sum;
            visible_sum = 0;
            for (int k = j-1; k >= 0; k--) {
                visible_sum++;
                if (forest[i][j] <= forest[i][k]){
                    break;
                }
            }
            current_score *= visible_sum;
            if (current_score > score) {
                score = current_score;
            }
        }
    }
    std::cout << score << std::endl;
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