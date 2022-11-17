#include "aoc_2015_04.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <unordered_set>
#include <tuple>
#include <openssl/md5.h>

void run_2015_4_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 4" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_4_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_4.txt");
    }

    std::string input;
    std::getline(file,input);
    std::cout << input <<std::endl;
    file.close();
}

void run_2015_4_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 4" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_4_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_4.txt");
    }
    std::string input;
    std::getline(file,input);
    std::cout << input <<std::endl;
    file.close();
}


void aoc_2015_04(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2015_4_part_1(test);
    }
    if (part_2) {
        run_2015_4_part_2(test);
    }
}