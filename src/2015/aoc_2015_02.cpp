#include "aoc_2015_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

void run_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_2.txt");
    }

    std::string input;
    int sum = 0;
    while (std::getline(file,input)) {
        std::vector<int> numbers;
        std::stringstream stream(input);
        std::string number;

        while (std::getline(stream, number, 'x')) {
            numbers.push_back(std::stoi(number));
        }

        int smallest = std::numeric_limits<int>::max();
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i+1; j< numbers.size(); j++) {
                int current = numbers[i]*numbers[j];

                sum += current*2;

                if (current < smallest) {
                    smallest = current;
                }
            }
        }
        sum += smallest;
    }
    std::cout << sum << std::endl;
    file.close();
}

void run_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_2.txt");
    }
    std::string input;
    int sum = 0;
    while (std::getline(file,input)) {
        std::vector<int> numbers;
        std::stringstream stream(input);
        std::string number;

        while (std::getline(stream, number, 'x')) {
            numbers.push_back(std::stoi(number));
        }

        int smallest = std::numeric_limits<int>::max();
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i+1; j< numbers.size(); j++) {
                int current = 2*(numbers[i]+numbers[j]);

                if (current < smallest) {
                    smallest = current;
                }
            }
        }
        sum += smallest + numbers[0]*numbers[1]*numbers[2];;
    }
    std::cout << sum << std::endl;
    file.close();
}


void aoc_2015_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_part_1(test);
    }
    if (part_2) {
        run_part_2(test);
    }
}