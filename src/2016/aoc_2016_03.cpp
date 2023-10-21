#include "aoc_2016_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <bits/stdc++.h>

void run_2016_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_3.txt");
    }
    std::string input;
    int answer = 0;
    int points[3];
    while (file >> points[0] >> points[1] >> points[2]) {
        std::sort(std::begin(points), std::end(points));
        if (points[2] < points[1] + points[0])
            answer++;
    }
    std::cout << answer << std::endl;
    file.close();
}

void run_2016_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 3" << std::endl;
    if (test) {
        file.open("../src/2016/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2016/input/day_3.txt");
    }
    std::string input;
    std::string answer;
    int x = 0;
    int y = 0;
    std::map<std::pair<int,int>, char> keypad = {
            {{2,-2}, '1'},
            {{1,-1}, '2'},
            {{2,-1}, '3'},
            {{3,-1}, '4'},
            {{0,0}, '5'},
            {{1,0}, '6'},
            {{2,0}, '7'},
            {{3,0}, '8'},
            {{4,0}, '9'},
            {{1,1}, 'A'},
            {{2,1}, 'B'},
            {{3,1}, 'C'},
            {{2,2}, 'D'}
    };
    while (std::getline(file, input)) {
        for (char ch: input) {
            switch (ch) {
                case 'L':
                    if (x > abs(y)) {
                        x--;
                    }
                    break;
                case 'R':
                    if (x < 4-abs(y)) {
                        x++;
                    }
                    break;
                case 'U':
                    if (y > -std::min(x, 4-x)) {
                        y--;
                    }
                    break;
                case 'D':
                    if (y < std::min(x,4-x)) {
                        y++;
                    }
                    break;
                default:
                    break;
            }
        }
        answer.push_back(keypad[{x,y}]);
    }

    std::cout << answer << std::endl;
    file.close();
}


void aoc_2016_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2016_3_part_1(test);
    }
    if (part_2) {
        run_2016_3_part_2(test);
    }
}