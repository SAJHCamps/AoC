#include "aoc_2020_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

void run_2020_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_3.txt");
    }
    std::string input;
    int count = 0;
    int x = 0;
    std::getline(file, input);
    int size = input.length();
    if (input[x] == '#')
        count++;
    x = (x+3)%size;
    while (std::getline(file, input)) {
        if (input[x] == '#')
            count++;
        x = (x+3)%size;
    }
    std::cout << count << std::endl;
    file.close();
}

void run_2020_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2020/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2020/input/day_3.txt");
    }
    std::string input;
    int correct = 0;
    while (std::getline(file, input)) {
        int sum = 0;
        int start = 0;
        int end =  input.find_first_not_of("0123456789");
        int min = std::stoi(input.substr(start, end));
        start = input.find_first_of("0123456789", end);
        end =  input.find_first_not_of("0123456789", start);
        int max = std::stoi(input.substr(start, end));
        char check = input[end + 1];
        if (input[end + min + 3] == check ^ input[end + max + 3] == check)
            correct++;
    }
    std::cout << correct << std::endl;
    file.close();
}


void aoc_2020_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2020_3_part_1(test);
    }
    if (part_2) {
        run_2020_3_part_2(test);
    }
}