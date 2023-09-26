#include "aoc_2016_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>

void run_2016_1_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_1_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_1.txt");
    }
    std::string input;
    int x = 0;
    int y = 0;
    int direction = 0;
    while (std::getline(file, input, ',')) {
        if (input.find('R') != std::string::npos){
            direction = (direction + 1) % 4;
        }
        else if (input.find('L') != std::string::npos){
            direction = (direction + 3) % 4;
        }
        int start = input.find_first_of("0123456789");
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        switch (direction) {
            case 0:
                x += amount;
                break;
            case 1:
                y += amount;
                break;
            case 2:
                x -= amount;
                break;
            case 3:
                y -= amount;
                break;
            default:
                std::cout << "I have a bad feeling about this" << std::endl;
        }
    }

    std::cout << abs(x) + abs(y) << std::endl;
    file.close();
}

void run_2016_1_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 1" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_1_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_1.txt");
    }
    std::string input;
    int x = 0;
    int y = 0;
    int direction = 0;
    std::set<std::pair<int,int>> visited;
    visited.insert(std::make_pair(x,y));
    while (std::getline(file, input, ',')) {
        if (input.find('R') != std::string::npos){
            direction = (direction + 1) % 4;
        }
        else if (input.find('L') != std::string::npos){
            direction = (direction + 3) % 4;
        }
        int start = input.find_first_of("0123456789");
        int end = input.find_first_not_of("0123456789", start);
        int amount  = std::stoi(input.substr(start, end));
        switch (direction) {
            case 0:
                for (int _ = 0; _ < amount; _++){
                    x++;
                    if (visited.find(std::make_pair(x,y)) != visited.end()) {
                        goto found;
                    }
                    else {
                        visited.insert(std::make_pair(x,y));
                    }
                }
                break;
            case 1:
                for (int _ = 0; _ < amount; _++){
                    y++;
                    if (visited.find(std::make_pair(x,y)) != visited.end()) {
                        goto found;
                    }
                    else {
                        visited.insert(std::make_pair(x,y));
                    }
                }
                break;
            case 2:
                for (int _ = 0; _ < amount; _++){
                    x--;
                    if (visited.find(std::make_pair(x,y)) != visited.end()) {
                        goto found;
                    }
                    else {
                        visited.insert(std::make_pair(x,y));
                    }
                }
                break;
            case 3:
                for (int _ = 0; _ < amount; _++){
                    y--;
                    if (visited.find(std::make_pair(x,y)) != visited.end()) {
                        goto found;
                    }
                    else {
                        visited.insert(std::make_pair(x,y));
                    }
                }
                break;
            default:
                std::cout << "I have a bad feeling about this" << std::endl;
        }
    }
    found:
    std::cout << abs(x) + abs(y) << std::endl;
    file.close();
}


void aoc_2016_01(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2016_1_part_1(test);
    }
    if (part_2) {
        run_2016_1_part_2(test);
    }
}