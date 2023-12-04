#include "aoc_2023_04.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

void run_2023_4_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 4" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_4_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_4.txt");
    }
    std::string input;
    int score = 0;
    while(std::getline(file,input)) {
        std::unordered_set<int> winners;
        int begin  = input.find_first_of(':');
        int seperator = input.find_first_of('|');
        int begin_number = input.find_first_of("1234567890", begin);
        int end_number = input.find_first_not_of("1234567890", begin_number);
        while (begin_number < seperator) {
            winners.insert(std::stoi(input.substr(begin_number, end_number-begin_number)));
            begin_number = input.find_first_of("1234567890", end_number);
            end_number = input.find_first_not_of("1234567890", begin_number);
        }
        int count = 0;
        begin_number = input.find_first_of("1234567890", seperator);
        end_number = input.find_first_not_of("1234567890", begin_number);
        while (begin_number != std::string::npos) {
            if (winners.find(std::stoi(input.substr(begin_number, end_number-begin_number))) != winners.end())
                count++;
            begin_number = input.find_first_of("1234567890", end_number);
            end_number = input.find_first_not_of("1234567890", begin_number);
        }
        if (count > 0){
            int card_score = 1;
            for (int i =0; i< count-1; i++) {
                card_score = card_score*2;
            }
            score += card_score;
        }
    }
    std::cout << score << std::endl;
    file.close();
}

void run_2023_4_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 4" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_4_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_4.txt");
    }
    std::string input;
    std::vector<std::string> cards;
    std::vector<int> amount_cards;
    while (std::getline(file,input)) {
        cards.push_back(input);
        amount_cards.push_back(1);
    }
    for (int card_index = 0; card_index < cards.size(); card_index++) {
        std::unordered_set<int> winners;
        int begin  = cards[card_index].find_first_of(':');
        int seperator = cards[card_index].find_first_of('|');
        int begin_number = cards[card_index].find_first_of("1234567890", begin);
        int end_number = cards[card_index].find_first_not_of("1234567890", begin_number);
        while (begin_number < seperator) {
            winners.insert(std::stoi(cards[card_index].substr(begin_number, end_number-begin_number)));
            begin_number = cards[card_index].find_first_of("1234567890", end_number);
            end_number = cards[card_index].find_first_not_of("1234567890", begin_number);
        }
        int count = 0;
        begin_number = cards[card_index].find_first_of("1234567890", seperator);
        end_number = cards[card_index].find_first_not_of("1234567890", begin_number);
        while (begin_number != std::string::npos) {
            if (winners.find(std::stoi(cards[card_index].substr(begin_number, end_number-begin_number))) != winners.end())
                count++;
            begin_number = cards[card_index].find_first_of("1234567890", end_number);
            end_number = cards[card_index].find_first_not_of("1234567890", begin_number);
        }
        for (int i = 1; i <= count; i++) {
            amount_cards[card_index+i] += amount_cards[card_index];
        }
    }

    int score = 0;
    for (int amount: amount_cards)
        score += amount;
    std::cout << score << std::endl;
    file.close();
}


void aoc_2023_04(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_4_part_1(test);
    }
    if (part_2) {
        run_2023_4_part_2(test);
    }
}