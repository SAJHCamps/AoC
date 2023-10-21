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
    int answer = 0;
    int points[3][3];
    while (file >> points[0][0] >> points[1][0] >> points[2][0] >> points[0][1] >> points[1][1] >> points[2][1] >> points[0][2] >> points[1][2] >> points[2][2]) {
        for (auto & point : points) {
            std::sort(std::begin(point), std::end(point));
            if (point[2] < point[1] + point[0])
                answer++;
        }
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