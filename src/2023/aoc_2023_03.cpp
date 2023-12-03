#include "aoc_2023_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int find_number(std::string schematic, int pos) {
    if ('0' <= schematic[pos] && '9' >= schematic[pos] ){
        int begin = pos -1;
        int end = pos+1;
        while ('0' <= schematic[begin] && '9' >= schematic[begin] && begin >= 0)
            begin--;
        while ('0' <= schematic[end] && '9' >= schematic[end] && end < schematic.size())
            end++;
        begin++;
        end--;
        return std::stoi(schematic.substr(begin, end-begin+1));
    }
    else {
        return -1;
    }
}

void run_2023_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_3.txt");
    }
    std::string input;
    std::vector<std::string> schematic;
    while(std::getline(file,input)) {
        schematic.push_back(input);
    }
    int score;
    for (int i = 0; i < schematic.size(); i++) {
        int current_symbol = schematic[i].find_first_of("0123456789");
        while (current_symbol != std::string::npos) {
            int end = current_symbol;
            while ('0' <= schematic[i][end] && '9' >= schematic[i][end] && end < schematic[i].size())
                end++;
            end--;
            bool connected = false;
            for (int j = -1; j<2; j++) {
                for (int k = -1; k<= end- current_symbol +1; k++) {
                    if (i+j >= 0 && i+j < schematic.size() && current_symbol+k >= 0 && current_symbol+k < schematic[0].size()) {
                        if ((schematic[i+j][current_symbol+k] < '0' || schematic[i+j][current_symbol+k] > '9') && schematic[i+j][current_symbol+k] != '.')
                            connected = true;
                    }
                }
            }
            if (connected)
                score += stoi(schematic[i].substr(current_symbol, end - current_symbol+1));
            current_symbol = schematic[i].find_first_of("0123456789", end+1);
        }
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2023_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_3.txt");
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


void aoc_2023_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_3_part_1(test);
    }
    if (part_2) {
        run_2023_3_part_2(test);
    }
}