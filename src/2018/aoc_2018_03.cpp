#include "aoc_2018_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <set>

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
    std::regex regex("#([0-9]*) @ ([0-9]*),([0-9]*): ([0-9]*)x([0-9]*)");
    std::smatch match;
    std::vector<std::vector<int>> entries;
    while(getline(file, input)) {
        if (std::regex_search(input, match, regex)) {
            std::vector<int> square = {std::stoi(match[1].str()), std::stoi(match[2].str()), std::stoi(match[3].str()),
                                       std::stoi(match[4].str()), std::stoi(match[5].str())};
            entries.push_back(square);
        }
    }
    int id;
    std::set<int> seen;

    for (int i = 0; i < entries.size(); i++) {
        for (int j = i+1; j < entries.size(); j++) {
            int start_match_x = entries[i][1];
            int start_check_x = entries[j][1];
            int stop_match_x = entries[i][3] + entries[i][1];
            int stop_check_x = entries[j][3] + entries[j][1];
            int start_match_y = entries[i][2];
            int start_check_y = entries[j][2];
            int stop_match_y = entries[i][4] + entries[i][2];
            int stop_check_y = entries[j][4] + entries[j][2];
            for (int x = std::max(start_match_x, start_check_x); x < std::min(stop_match_x, stop_check_x); x++) {
                for (int y = std::max(start_match_y, start_check_y); y < std::min(stop_match_y, stop_check_y); y++) {
                    seen.insert(x + 1000* y);
                }
            }
        }
    }
    std::cout << seen.size() << std::endl;
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
    std::regex regex("#([0-9]*) @ ([0-9]*),([0-9]*): ([0-9]*)x([0-9]*)");
    std::smatch match;
    std::vector<std::vector<int>> entries;
    while(getline(file, input)) {
        if (std::regex_search(input, match, regex)) {
            std::vector<int> square = {std::stoi(match[1].str()), std::stoi(match[2].str()), std::stoi(match[3].str()),
                             std::stoi(match[4].str()), std::stoi(match[5].str())};
            entries.push_back(square);
        }
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