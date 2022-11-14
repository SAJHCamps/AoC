#include "aoc_2015_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <unordered_set>
#include <tuple>

void run_2015_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_3.txt");
    }

    std::string input;
    std::getline(file,input);
    int x = 0;
    int y = 0;
    std::unordered_set<int> set;
    set.insert(x*8193 + y);
    for (auto &ch :input) {
        switch (ch) {
            case 'v':
                y--;
                break;
            case '^':
                y++;
                break;
            case '<':
                x++;
                break;
            case '>' :
                x--;
                break;
            default:
                break;
        }
        set.insert(x*8193 + y);
    }

    std::cout << set.size() << std::endl;
    file.close();
}

void run_2015_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
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


void aoc_2015_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2015_3_part_1(test);
    }
    if (part_2) {
        run_2015_3_part_2(test);
    }
}