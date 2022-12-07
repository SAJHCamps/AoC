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

void run_2022_5_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 5" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_5_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_5.txt");
    }
    std::string input;
    std::getline(file,input);
    std::vector<std::string> initial = {};
    while (input.length() != 0) {
        initial.push_back(input);
        std::getline(file,input);
    }
    std::vector<std::vector<char>> stacks;
    int number_stacks = (initial[initial.size()-1].length() + 2)/4;
    for (int i = 0; i < number_stacks; i++) {
        stacks.push_back({});
    }

    for (int i = initial.size()-2;i >= 0; i--) {
        std::string current_line  = initial[i];
        for (int j = 1; j < current_line.length(); j += 4) {
            if (current_line[j] != ' ') {
                stacks[j / 4].push_back(current_line[j]);
            }
        }
    }

    while (std::getline(file,input)) {
        int start = input.find_first_of("0123456789");
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        start = input.find_first_of("0123456789", end);
        end = input.find_first_not_of("0123456789", start);
        int from  = std::stoi(input.substr(start, end))-1;
        start = input.find_first_of("0123456789", end);
        end = input.find_first_not_of("0123456789", start);
        int to  = std::stoi(input.substr(start, end))-1;
        for (int i = 0; i < amount; i++) {
            char result = stacks[from].back();
            stacks[from].pop_back();
            stacks[to].push_back(result);
        }
    }
    std::string answer;
    for (int i = 0; i < number_stacks; i++) {
        answer += stacks[i].back();
    }

    std::cout << answer << std::endl;
    file.close();
}

void run_2022_5_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 4" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_5_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_5.txt");
    }
    std::string input;
    std::getline(file,input);
    std::vector<std::string> initial = {};
    while (input.length() != 0) {
        initial.push_back(input);
        std::getline(file,input);
    }
    std::vector<std::vector<char>> stacks;
    int number_stacks = (initial[initial.size()-1].length() + 2)/4;
    for (int i = 0; i < number_stacks; i++) {
        stacks.push_back({});
    }

    for (int i = initial.size()-2;i >= 0; i--) {
        std::string current_line  = initial[i];
        for (int j = 1; j < current_line.length(); j += 4) {
            if (current_line[j] != ' ') {
                stacks[j / 4].push_back(current_line[j]);
            }
        }
    }

    while (std::getline(file,input)) {
        int start = input.find_first_of("0123456789");
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        start = input.find_first_of("0123456789", end);
        end = input.find_first_not_of("0123456789", start);
        int from  = std::stoi(input.substr(start, end))-1;
        start = input.find_first_of("0123456789", end);
        end = input.find_first_not_of("0123456789", start);
        int to  = std::stoi(input.substr(start, end))-1;
        std::vector<char> temp= {};
        for (int i = 0; i < amount; i++) {
            char result = stacks[from].back();
            stacks[from].pop_back();
            temp.push_back(result);
        }
        for (int i = 0; i < amount; i++) {
            char result = temp.back();
            temp.pop_back();
            stacks[to].push_back(result);
        }
    }
    std::string answer;
    for (int i = 0; i < number_stacks; i++) {
        answer += stacks[i].back();
    }

    std::cout << answer << std::endl;
    file.close();
}


void aoc_2022_05(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_5_part_1(test);
    }
    if (part_2) {
        run_2022_5_part_2(test);
    }
}