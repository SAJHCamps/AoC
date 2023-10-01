#include "aoc_2016_01.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>

void run_2016_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_2.txt");
    }
    std::string input;
    int answer = 0;
    int x = 1;
    int y = 1;
    while (std::getline(file, input)) {
        for (char ch: input) {
            switch (ch) {
                case 'L':
                    if (x > 0) {
                        x--;
                    }
                    break;
                case 'R':
                    if (x < 2) {
                        x++;
                    }
                    break;
                case 'U':
                    if (y > 0) {
                        y--;
                    }
                    break;
                case 'D':
                    if (y < 2) {
                        y++;
                    }
                    break;
                default:
                    break;
            }
        }
        answer = 10*answer + x + 1 + 3*y;
    }

    std::cout << answer << std::endl;
    file.close();
}

void run_2016_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_2.txt");
    }
    std::string input;
    int answer = 0;
    int x = 1;
    int y = 1;
    while (std::getline(file, input)) {
        for (char ch: input) {
            switch (ch) {
                case 'L':
                    if (x > 0) {
                        x--;
                    }
                    break;
                case 'R':
                    if (x < 2) {
                        x++;
                    }
                    break;
                case 'U':
                    if (y > 0) {
                        y--;
                    }
                    break;
                case 'D':
                    if (y < 2) {
                        y++;
                    }
                    break;
                default:
                    break;
            }
        }
        answer = 10*answer + x + 1 + 3*y;
    }

    std::cout << answer << std::endl;
    file.close();
}


void aoc_2016_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2016_2_part_1(test);
    }
    if (part_2) {
        run_2016_2_part_2(test);
    }
}