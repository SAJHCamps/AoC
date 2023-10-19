#include "aoc_2019_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run_2019_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_2.txt");
    }
    std::vector<int> program;
    std::string  input;
    while (getline(file,input,  ',')) {
        program.push_back(std::stoi(input));
    }
    if (!test) {
        program[1] = 12;
        program[2] = 2;
    }
    int current = 0;
    bool halt = false;
    while (!halt) {
        switch (program[current]) {
            case 1: {
                int index_store = program[current+3];
                int index_add_1 = program[current+1];
                int index_add_2 = program[current+2];
                program[index_store] = program[index_add_1] + program[index_add_2];
                current += 4;
                break;
            }
            case 2: {
                int index_store = program[current+3];
                int index_add_1 = program[current+1];
                int index_add_2 = program[current+2];
                program[index_store] = program[index_add_1] * program[index_add_2];
                current += 4;
                break;
            }
            case 99: {
                halt = true;
                break;
            }
            default:
                std::cout << "I have a bad feeling about this" << std::endl;
        }
    }
    std::cout << program[0] << std::endl;
    file.close();
}

void run_2019_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 1" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_2.txt");
    }
    std::string input;
    int sum = 0;
    while (getline(file,input)) {
        int unchecked = std::stoi(input)/3 - 2;
        while (unchecked > 0) {
            sum += unchecked;
            unchecked = unchecked / 3 - 2;
        }
    }
    std::cout << sum << std::endl;
    file.close();
}


void aoc_2019_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2019_2_part_1(test);
    }
    if (part_2) {
        run_2019_2_part_2(test);
    }
}