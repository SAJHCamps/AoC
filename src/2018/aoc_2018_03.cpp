#include "aoc_2018_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <bits/stdc++.h>

void run_2018_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_3.txt");
    }
    std::string input;
    int two_count = 0;
    int three_count = 0;
    while (std::getline(file,input)) {
        std::set<char> characters;
        for (char ch: input) {
            characters.insert(ch);
        }
        bool two_count_current = false;
        bool three_count_current = false;
        for (char ch: characters) {
            switch (std::count(input.begin(), input.end(), ch)) {
                case 2:
                    two_count_current = true;
                    break;
                case 3:
                    three_count_current = true;
                    break;
                default:
                    break;
            }
        }
        two_count += two_count_current;
        three_count += three_count_current;
    }
    std::cout << two_count*three_count << std::endl;
    file.close();
}

void run_2018_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_3.txt");
    }
    std::string input;
    std::string answer;
    std::set<std::string> seen;
    while (getline(file, input)) {
        for (int i = 0; i < input.length(); i++) {
            std::string first = input.substr(0, i);
            std::string last =  input.substr(i+1, input.length()-i-1);
            std::string current = first + last;
            if (seen.find(current) != seen.end()) {
                answer = current;
                goto brk;
            }
        }
        for (int i = 0; i < input.length(); i++) {
            std::string first = input.substr(0, i);
            std::string last =  input.substr(i+1, input.length()-i-1);
            seen.insert(first + last);
        }
    }
    brk:
    std::cout << answer << std::endl;
    file.close();
}


void aoc_2018_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2018_3_part_1(test);
    }
    if (part_2) {
        run_2018_3_part_2(test);
    }
}