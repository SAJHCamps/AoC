#include "aoc_2017_03.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <utility>

void run_2017_3_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 3" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_3_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_3.txt");
    }
    int target;
    file >> target;
    int rank = 1;
    while (rank*rank < target) {
        rank += 2;
    }
    int steps = (rank*rank - target)%(rank -1);
    std::cout << rank/2 + std::abs(steps - rank/2)<< std::endl;
    file.close();
}

void run_2017_3_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 2" << std::endl;
    if (test) {
        file.open("../src/2017/test/test_3_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2017/input/day_3.txt");
    }
    int target;
    file >> target;
    int answer;
    int rank = 1;
    std::map<std::pair<int,int>, int> space  = {{{0, 0}, 1}};
    while (true) {
        for (int i = -rank +1; i <= rank; i++) {
            int result =    space[{rank-1, i-1}] + space[{rank, i-1}] + space[{rank+1, i-1}] +
                            space[{rank-1, i}]   + space[{rank, i}]   + space[{rank+1, i}] +
                            space[{rank-1, i+1}] + space[{rank, i+1}] + space[{rank+1, i+1}];
            if (result > target){
                answer = result;
                goto stop;
            }
            else
                space[{rank, i}] = result;
        }
        for (int i = rank -1; i >= -rank; i--) {
            int result =    space[{i-1, rank-1}] + space[{i, rank-1}] + space[{i+1, rank-1}] +
                            space[{i-1, rank}]   + space[{i, rank}]   + space[{i+1, rank}] +
                            space[{i-1, rank+1}] + space[{i, rank+1}] + space[{i+1, rank+1}];
            if (result > target){
                answer = result;
                goto stop;
            }
            else
                space[{i, rank}] = result;
        }
        for (int i = rank -1; i >= -rank; i--) {
            int result =    space[{-rank-1, i-1}] + space[{-rank, i-1}] + space[{-rank+1, i-1}] +
                            space[{-rank-1, i}]   + space[{-rank, i}]   + space[{-rank+1, i}] +
                            space[{-rank-1, i+1}] + space[{-rank, i+1}] + space[{-rank+1, i+1}];
            if (result > target){
                answer = result;
                goto stop;
            }
            else
                space[{-rank, i}] = result;
        }
        for (int i = -rank +1; i <= rank; i++) {
            int result =    space[{i-1, -rank-1}] + space[{i, -rank-1}] + space[{i+1, -rank-1}] +
                            space[{i-1, -rank}]   + space[{i, -rank}]   + space[{i+1, -rank}] +
                            space[{i-1, -rank+1}] + space[{i, -rank+1}] + space[{i+1, -rank+1}];
            if (result > target){
                answer = result;
                goto stop;
            }
            else
                space[{i, -rank}] = result;
        }
        rank++;
    }
stop:
    std::cout << answer << std::endl;
    file.close();
}


void aoc_2017_03(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2017_3_part_1(test);
    }
    if (part_2) {
        run_2017_3_part_2(test);
    }
}