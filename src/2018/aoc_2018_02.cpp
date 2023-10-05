#include "aoc_2018_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <limits>
#include <bits/stdc++.h>

void run_2018_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_2.txt");
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

void run_2018_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2018/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2018/input/day_2.txt");
    }
    std::string input;
    int current = 0;
    std::vector<int> changes;
    std::set<int> seen;
    seen.insert(current);
    while (std::getline(file,input)) {
        if (input[0] == '+') {
            changes.push_back(stoi(input.substr(1,std::string::npos)));
        }
        else if (input[0] == '-') {
            changes.push_back(stoi(input));
        }
        else {
//            std::cout << "I have a bad feeling about this" << std::endl;
        }
    }
    int shift = 0;
    for (int i: changes) {
        shift += i;
    }
    std::vector<std::vector<int>> classes;
    for (int i=0; i < shift; i++) {
        std::vector<int> class_vec;
        int sum = 0;
        for (int change: changes) {
            if (((sum%shift)+shift)%shift == i) {
               class_vec.push_back(sum);
            }
            sum += change;
        }
        classes.push_back(class_vec);
    }
    int lowest_freq;
    int min_shifts = std::numeric_limits<int>::max();
    current = 0;
    for (int change: changes) {
        int index = ((current%shift)+shift)%shift;
        for (int other_freq: classes[index]) {
            int shifts = (other_freq-current)/shift;
            if (shifts < min_shifts && shifts > 0) {
                min_shifts = shifts;
                lowest_freq = other_freq;
            }
        }
        current += change;
    }


    std::cout << lowest_freq << std::endl;
    file.close();
}


void aoc_2018_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2018_2_part_1(test);
    }
    if (part_2) {
        run_2018_2_part_2(test);
    }
}