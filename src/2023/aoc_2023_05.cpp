#include "aoc_2023_05.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct map {
    long long start_input;
    long long start_output;
    long long range;
};

bool map_compare(map a, map b) {
    return a.start_input < b.start_input;
}

void run_2023_5_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 5" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_5_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_5.txt");
    }
    std::string input;
    std::getline(file, input);
    std::vector<long long> points;
    int current = input.find_first_of("0123456789");
    int end = input.find_first_not_of("0123456789", current);
    while (current != std::string::npos) {
        points.push_back(std::stoll(input.substr(current,end - current)));
        current = input.find_first_of("0123456789", end);
        end = input.find_first_not_of("0123456789", current);
    }

    std::vector<std::vector<map>> conversions;
    for (int i = 0; i < 7; i++) {
        conversions.push_back({});
    }
    int current_map = -1;

    while (std::getline(file, input)) {
        if (input.find(':') != std::string::npos) {
            current_map++;
        } else if (input[0] >= '0' && input[0] <= '9') {
            map entry;
            current = input.find_first_of("0123456789");
            end = input.find_first_not_of("0123456789", current);
            entry.start_output =  std::stoll(input.substr(current,end - current));
            current = input.find_first_of("0123456789", end);
            end = input.find_first_not_of("0123456789", current);
            entry.start_input =  std::stoll(input.substr(current,end - current));
            current = input.find_first_of("0123456789", end);
            end = input.find_first_not_of("0123456789", current);
            entry.range =  std::stoll(input.substr(current,end - current));
            conversions[current_map].push_back(entry);
        }
    }
    for (int i = 0; i < 7; i++) {
        std::sort(conversions[i].begin(), conversions[i].end(), map_compare);
        for (int j = 0; j < points.size(); j++) {
            int begin = conversions[i].size()-1;
            while (conversions[i][begin].start_input > points[j] && begin >= 1)
                begin--;

            if (conversions[i][begin].start_input <= points[j]
                    && conversions[i][begin].start_input + conversions[i][begin].range > points[j])
                points[j] = conversions[i][begin].start_output - conversions[i][begin].start_input + points[j];
        }
    }

    std::cout << *std::min_element(points.begin(), points.end()) << std::endl;
    file.close();
}

void run_2023_5_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 5" << std::endl;
    if (test) {
        file.open("../src/2023/test/test_5_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2023/input/day_5.txt");
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


void aoc_2023_05(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2023_5_part_1(test);
    }
    if (part_2) {
        run_2023_5_part_2(test);
    }
}