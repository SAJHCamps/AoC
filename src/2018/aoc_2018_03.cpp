#include "aoc_2018_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <bits/stdc++.h>
#include <map>

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
    std::regex regex("#[0-9]* @ ([0-9]*),([0-9]*): ([0-9]*)x([0-9]*)");
    std::smatch match;
    std::map<int,int> field;
    while(getline(file, input)) {
        if (std::regex_search(input, match, regex)) {
            for (int i = std::stoi(match[1].str()); i < std::stoi(match[1].str()) + std::stoi(match[3].str()); i++) {
                for (int j = std::stoi(match[2].str()); j < std::stoi(match[2].str()) + std::stoi(match[4].str()); j++) {
                    field[i+j*1000] = field[i+j*1000] + 1;
                }
            }
        }
    }
    int score = 0;
    for (auto i : field) {
        if (i.second >= 2)
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
    std::string answer;
    std::set<std::string> seen;
    while (getline(file, input)) {
        for (int i = 0; i < input.length(); i++) {
            std::string first = input.substr(0, i);
            std::string last =  input.substr(i+1, input.length()-i-1);
            std::string current = first + last;
            if (seen.find(current) != seen.end()) {
                answer = current;
                goto brk;
            }
        }
        for (int i = 0; i < input.length(); i++) {
            std::string first = input.substr(0, i);
            std::string last =  input.substr(i+1, input.length()-i-1);
            seen.insert(first + last);
        }
    }
    brk:
    std::cout << answer << std::endl;
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