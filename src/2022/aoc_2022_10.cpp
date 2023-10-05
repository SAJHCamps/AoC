#include "aoc_2022_10.hpp"
#include <iostream>
#include <fstream>
#include <string>

void run_2022_10_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 10" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_10_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_10.txt");
    }
    std::string input;
    int score = 0;
    int X = 1;
    int cycles = 1;
    while (std::getline(file, input)) {
        switch (input[0]) {
            case 'n':
                if ((cycles - 20) % 40 == 0) {
                    score += X*cycles;
                }
                cycles++;
                break;
            case 'a':
                if ((cycles - 20) % 40 == 0 && cycles >= 20) {
                    score += X*cycles;
                }
                cycles ++;
                if ((cycles - 20) % 40 == 0 && cycles >= 20) {
                    score += X*cycles;
                }
                cycles ++;
                X += std::stoi(input.substr(5, std::string::npos));
                break;
            default:
                break;
        }
    }

    std::cout << score << std::endl;
    file.close();
}

void run_2022_10_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 10" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_10_2.txt");
        std::string answer;
        std::cout << "Test should give: " << std::endl;
        for (int _ = 0; _ < 6; _++) {
            std::getline(file,answer);
            std::cout << answer << std::endl;
        }
    }
    else {
        file.open("../src/2022/input/day_10.txt");
    }
    std::string input;
    int X = 1;
    int cycles = 1;
    while (std::getline(file, input)) {
        switch (input[0]) {
            case 'n':
                if ((cycles % 40) - X <= 2 && (cycles % 40) - X >= 0) {
                    std::cout << '#';
                }
                else {
                    std::cout << '.';
                }
                if (cycles % 40 == 0) {
                    std::cout << std::endl;
                }
                cycles++;
                break;
            case 'a':
                if ((cycles % 40) - X <= 2 && (cycles % 40) - X >= 0) {
                    std::cout << '#';
                }
                else {
                    std::cout << '.';
                }
                if (cycles % 40 == 0) {
                    std::cout << std::endl;
                }
                cycles++;

                if ((cycles % 40) - X <= 2 && (cycles % 40) - X >= 0) {
                    std::cout << '#';
                }
                else {
                    std::cout << '.';
                }
                if (cycles % 40 == 0) {
                    std::cout << std::endl;
                }
                cycles++;

                X += std::stoi(input.substr(5, std::string::npos));
                break;
            default:
                break;
        }
    }
    file.close();
}


void aoc_2022_10(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_10_part_1(test);
    }
    if (part_2) {
        run_2022_10_part_2(test);
    }
}