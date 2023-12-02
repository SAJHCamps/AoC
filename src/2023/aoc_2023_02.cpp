#include "aoc_2023_02.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run_2023_2_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_2_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_2.txt");
    }
    std::string input;
    int score = 0;
    int line = 0;
    while(std::getline(file,input)) {
        line++;
        int current = input.find_first_of(':');
        int end = input.find_first_of(';');
        bool possible = true;
        while (current != std::string::npos) {
            std::string game_input = input.substr(current+1, end - current -1);
            int current_hand = 0;
            int end_hand = game_input.find_first_of(',');
            while (current_hand != std::string::npos) {
                std::string hand_input = game_input.substr(current_hand+1, end_hand- current_hand -1);
                int amount = std::stoi(hand_input.substr(hand_input.find_first_of("0123456789")));
                if ((hand_input.find("red") != std::string::npos && amount > 12)
                    || (hand_input.find("green") != std::string::npos && amount > 13)
                    || (hand_input.find("blue") != std::string::npos && amount > 14)) {
                    possible = false;
                }
                current_hand = end_hand;
                end_hand = game_input.find_first_of(',', end_hand+1);
            }
            current = end;
            end = input.find_first_of(';', end+1);
        }
        if (possible)
            score += line;
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2023_2_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_2_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_2.txt");
    }
    std::string input;
    int score = 0;
    while(std::getline(file,input)) {
        int current = input.find_first_of(':');
        int end = input.find_first_of(';');
        int colours[] = {0,0,0};
        while (current != std::string::npos) {
            std::string game_input = input.substr(current+1, end - current -1);
            int current_hand = 0;
            int end_hand = game_input.find_first_of(',');
            while (current_hand != std::string::npos) {
                std::string hand_input = game_input.substr(current_hand+1, end_hand- current_hand -1);
                int amount = std::stoi(hand_input.substr(hand_input.find_first_of("0123456789")));
                if (hand_input.find("red") != std::string::npos && amount > colours[0]) {
                    colours[0] = amount;
                } else if (hand_input.find("green") != std::string::npos && amount > colours[1]) {
                    colours[1] = amount;
                } else if (hand_input.find("blue") != std::string::npos && amount > colours[2]) {
                    colours[2] = amount;
                }
                current_hand = end_hand;
                end_hand = game_input.find_first_of(',', end_hand+1);
            }
            current = end;
            end = input.find_first_of(';', end+1);
        }
        score += colours[0] * colours[1] * colours[2];
    }
    std::cout << score << std::endl;
    file.close();
}


void aoc_2023_02(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_2_part_1(test);
    }
    if (part_2) {
        run_2023_2_part_2(test);
    }
}