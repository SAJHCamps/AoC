#include "aoc_2023_04.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run_2023_4_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 4" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_4_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_4.txt");
    }
    std::string input;
    std::vector<std::string> schematic;
    while(std::getline(file,input)) {
        schematic.push_back(input);
    }
    int score = 0;
    for (int i = 0; i < schematic.size(); i++) {
        int current_symbol = schematic[i].find_first_of("0123456789");
        while (current_symbol != std::string::npos) {
            int end = current_symbol;
            while ('0' <= schematic[i][end] && '9' >= schematic[i][end] && end < schematic[i].size())
                end++;
            end--;
            bool connected = false;
            for (int j = -1; j<2; j++) {
                for (int k = -1; k<= end- current_symbol +1; k++) {
                    if (i+j >= 0 && i+j < schematic.size() && current_symbol+k >= 0 && current_symbol+k < schematic[0].size()) {
                        if ((schematic[i+j][current_symbol+k] < '0' || schematic[i+j][current_symbol+k] > '9') && schematic[i+j][current_symbol+k] != '.')
                            connected = true;
                    }
                }
            }
            if (connected)
                score += stoi(schematic[i].substr(current_symbol, end - current_symbol+1));
            current_symbol = schematic[i].find_first_of("0123456789", end+1);
        }
    }
    std::cout << score << std::endl;
    file.close();
}

int find_number(std::string line, int pos) {
    if (pos < 0 && pos >= line.size())
        return -1;
    if (line[pos] < '0' || line[pos] > '9')
        return -1;
    int end = pos;
    while ('0' <= line[end] && '9' >= line[end] && end < line.size())
        end++;
    end--;
    int begin = pos;
    while ('0' <= line[begin] && '9' >= line[begin] && begin >= 0)
        begin--;
    begin++;
    return std::stoi(line.substr(begin, end - begin+1));
}

void run_2023_4_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 4" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_4_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_4.txt");
    }
    std::string input;
    std::vector<std::string> schematic;
    while(std::getline(file,input)) {
        schematic.push_back(input);
    }
    int score = 0;
    for (int i = 0; i < schematic.size(); i++) {
        int current_symbol = schematic[i].find_first_of('*');
        while (current_symbol != std::string::npos) {
            std::vector<int> found;
            if (i > 0) {
                if (schematic[i-1][current_symbol] >= '0' && schematic[i-1][current_symbol] <= '9') {
                    found.push_back(find_number(schematic[i-1], current_symbol));
                }
                else {
                    int left_number = find_number(schematic[i-1], current_symbol-1);
                    int right_number = find_number(schematic[i-1], current_symbol+1);
                    if (left_number > 0)
                        found.push_back(left_number);
                    if (right_number > 0)
                        found.push_back(right_number);
                }
            }
            if (i < schematic.size()-1) {
                if (schematic[i+1][current_symbol] >= '0' && schematic[i+1][current_symbol] <= '9') {
                    found.push_back(find_number(schematic[i+1], current_symbol));
                }
                else {
                    int left_number = find_number(schematic[i+1], current_symbol-1);
                    int right_number = find_number(schematic[i+1], current_symbol+1);
                    if (left_number > 0)
                        found.push_back(left_number);
                    if (right_number > 0)
                        found.push_back(right_number);
                }
            }
            int left_number = find_number(schematic[i], current_symbol-1);
            int right_number = find_number(schematic[i], current_symbol+1);
            if (left_number > 0)
                found.push_back(left_number);
            if (right_number > 0)
                found.push_back(right_number);

            if (found.size() == 2) {
                score += found[0]*found[1];
            }
            current_symbol = schematic[i].find_first_of('*', current_symbol+1);
        }
    }
    std::cout << score << std::endl;
    file.close();
}


void aoc_2023_04(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_4_part_1(test);
    }
    if (part_2) {
        run_2023_4_part_2(test);
    }
}