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
    std::getline(file,input);
    int current_number = -1;
    unsigned char hashed[MD5_DIGEST_LENGTH];
    int sum;
    do {
        current_number++;
        std::string current = input + std::to_string(current_number);
        MD5((unsigned char*) current.c_str(), current.size(), hashed);
        sum = hashed[0] + hashed[1] + hashed[2]/16;
    } while (sum != 0);

    std::cout << current_number <<std::endl;
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
    int current_number = -1;
    unsigned char hashed[MD5_DIGEST_LENGTH];
    int sum;
    do {
        current_number++;
        std::string current = input + std::to_string(current_number);
        MD5((unsigned char*) current.c_str(), current.size(), hashed);
        sum = hashed[0] + hashed[1] + hashed[2];
    } while (sum != 0);

    std::cout << current_number <<std::endl;
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