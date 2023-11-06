#include "aoc_2019_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run_2019_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_3.txt");
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

void run_2019_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 3 day 1" << std::endl;
    if (test) {
        file.open("../src/2019/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2019/input/day_3.txt");
    }
    std::vector<int> program;
    std::string  input;
    while (getline(file,input,  ',')) {
        program.push_back(std::stoi(input));
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            std::vector<int> memory  = program;
            memory[1] = i;
            memory[2] = j;
            int current = 0;
            bool halt = false;
            while (!halt) {
                switch (memory[current]) {
                    case 1: {
                        int index_store = memory[current + 3];
                        int index_add_1 = memory[current + 1];
                        int index_add_2 = memory[current + 2];
                        memory[index_store] = memory[index_add_1] + memory[index_add_2];
                        current += 4;
                        break;
                    }
                    case 2: {
                        int index_store = memory[current + 3];
                        int index_add_1 = memory[current + 1];
                        int index_add_2 = memory[current + 2];
                        memory[index_store] = memory[index_add_1] * memory[index_add_2];
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
            if (memory[0]== 19690720) {
                std::cout << i*100 + j << std::endl;
                goto done;
            }
        }
    }
    done:
    file.close();
}


void aoc_2019_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2019_3_part_1(test);
    }
    if (part_2) {
        run_2019_3_part_2(test);
    }
}