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

void run_2015_5_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 5" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_5_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_5.txt");
    }

    std::string input;
    int nice_sum = 0;
    while (std::getline(file,input)) {
        if (input.find("ab") == std::string::npos && input.find("cd") == std::string::npos && input.find("pq") == std::string::npos && input.find("xy") == std::string::npos) {

            int vowels = 0;
            char previous = 0;
            bool doubles = false;
            for (auto &ch : input) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                }
                if (previous == ch) {
                    doubles = true;
                }
                previous = ch;
            }

            if (doubles && vowels >= 3) {
                nice_sum++;
            }
        }
    }

    std::cout << nice_sum <<std::endl;
    file.close();
}

void run_2015_5_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 5" << std::endl;
    if (test) {
        file.open("../src/2015/test/test_5_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2015/input/day_5.txt");
    }
    std::string input;
    std::getline(file,input);

    std::cout << input <<std::endl;
    file.close();
}


void aoc_2015_05(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2015_5_part_1(test);
    }
    if (part_2) {
        run_2015_5_part_2(test);
    }
}