#include "aoc_2021_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <queue>

void run_2021_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_3.txt");
    }
    std::string input;
    int lines = 0;
    int occurrence[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    while (std::getline(file,input)) {
        for (int i = 0; i < input.size(); i++) {
            occurrence[i] += input[i] - '0';
        }
        lines++;
    }
    int gamma = 0;
    int epsilon = 0;
    for (int i = 0; i < input.size(); i++) {
        if (occurrence[i]*2 > lines) {
            gamma  = gamma*2 + 1;
            epsilon = epsilon*2;
        }
        else {
            gamma  = gamma*2;
            epsilon = epsilon*2 + 1;
        }
    }
    std::cout << gamma * epsilon << std::endl;
    file.close();
}

void run_2021_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2021/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2021/input/day_3.txt");
    }
    std::string input;
    std::vector<std::string> total_lines;
    while (std::getline(file,input)) {
        total_lines.push_back(input);
    }
    std::vector<std::string> oxygen_lines (total_lines.size());
    std::copy(total_lines.begin(), total_lines.end(),oxygen_lines.begin());

    for (int bit = 0; bit < input.size(); bit++){
        if (oxygen_lines.size() == 1)
            break;
        int occurrence = 0;
        for (std::string line :oxygen_lines) {
            occurrence += line[bit] - '0';
        }
        int target;
        if (2*occurrence >= oxygen_lines.size()) {
            target = 1;
        }
        else {
            target = 0;
        }
        for (int i = 0; i < oxygen_lines.size(); i++) {
            if (oxygen_lines[i][bit]-'0' != target) {
                oxygen_lines.erase(oxygen_lines.begin()+i);
                i--;
            }
        }
    }

    std::vector<std::string> scrub_lines (total_lines.size());
    std::copy(total_lines.begin(), total_lines.end(),scrub_lines.begin());

    for (int bit = 0; bit < input.size(); bit++){
        if (scrub_lines.size() == 1) {
            break;
        }
        int occurrence = 0;
        for (std::string line :scrub_lines) {
            occurrence += line[bit] - '0';
        }
        int target;
        if (2*occurrence >= scrub_lines.size())
            target = 0;
        else
            target = 1;

        for (int i = 0; i < scrub_lines.size(); i++) {
            if (scrub_lines[i][bit]-'0' != target) {
                scrub_lines.erase(scrub_lines.begin()+i);
                i--;
            }
        }
    }

    std::cout << std::stoi(scrub_lines[0], nullptr,2) * std::stoi(oxygen_lines[0], nullptr,2) << std::endl;
    file.close();
}


void aoc_2021_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2021_3_part_1(test);
    }
    if (part_2) {
        run_2021_3_part_2(test);
    }
}