#include "aoc_2018_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <sstream>

void run_2018_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_3.txt");
    }
    std::string input;
    std::vector<std::vector<int>> entries;
    while(getline(file, input)) {
        std::stringstream ss(input);
        std::vector<int> square(5,0);
        char ch;
        ss >> ch >> square[0] >> ch >> square[1] >> ch >> square[2] >> ch >> square[3] >> ch >> square[4] >> ch >> square[5];
        entries.push_back(square);
    }
    std::vector<int> seen(1000000, 0);

    for (int i = 0; i < entries.size(); i++) {
        int start_match_x = entries[i][1];
        int stop_match_x = entries[i][3] + entries[i][1];
        int start_match_y = entries[i][2];
        int stop_match_y = entries[i][4] + entries[i][2];
        for (int x = start_match_x; x < stop_match_x; x++) {
            for (int y = start_match_y; y < stop_match_y; y++) {
                seen[x + 1000* y]++;
            }
        }
    }
    int score =0;
    for (int i: seen) {
        if (i > 1)
            score++;
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2018_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_3.txt");
    }
    std::string input;
    std::vector<std::vector<int>> entries;
    while(getline(file, input)) {
        std::stringstream ss(input);
        std::vector<int> square(5,0);
        char ch;
        ss >> ch >> square[0] >> ch >> square[1] >> ch >> square[2] >> ch >> square[3] >> ch >> square[4] >> ch >> square[5];
        entries.push_back(square);
    }
    int id;
    for (auto square :entries) {
        bool overlap = false;
        for (auto check: entries) {
            if (square == check) {
                continue;
            }
            int start_match_x = square[1];
            int start_check_x = check[1];
            int size_match_x = square[3];
            int size_check_x = check[3];
            int start_match_y = square[2];
            int start_check_y = check[2];
            int size_match_y = square[4];
            int size_check_y = check[4];
            if (start_match_x < start_check_x + size_check_x && start_match_y < start_check_y + size_check_y &&
                start_check_x < start_match_x + size_match_x && start_check_y < start_match_y + size_match_y) {
                overlap = true;
                break;
            }
        }
        if (!overlap) {
            id = square[0];
            break;
        }
    }
    std::cout << id << std::endl;
    file.close();
}


void aoc_2018_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2018_3_part_1(test);
    }
    if (part_2) {
        run_2018_3_part_2(test);
    }
}