#include <iostream>
#include <chrono>
#include <getopt.h>
#include <vector>

//bunch of imports
//2015
#include "2015/aoc_2015_01.hpp"
#include "2015/aoc_2015_02.hpp"
#include "2015/aoc_2015_03.hpp"
#include "2015/aoc_2015_04.hpp"
#include "2015/aoc_2015_05.hpp"
#include "2015/aoc_2015_06.hpp"

//2016
#include "2016/aoc_2016_01.hpp"

//2017
#include "2017/aoc_2017_01.hpp"

//2018
#include "2018/aoc_2018_01.hpp"

//2022
#include "2022/aoc_2022_01.hpp"
#include "2022/aoc_2022_02.hpp"
#include "2022/aoc_2022_03.hpp"
#include "2022/aoc_2022_04.hpp"
#include "2022/aoc_2022_05.hpp"
#include "2022/aoc_2022_06.hpp"
#include "2022/aoc_2022_07.hpp"
#include "2022/aoc_2022_08.hpp"
#include "2022/aoc_2022_09.hpp"
#include "2022/aoc_2022_10.hpp"
#include "2022/aoc_2022_11.hpp"

//update when starting new year to ease specification
#define MAX_YEAR 2022

struct ProgramOptions {
    int year = MAX_YEAR;
    int day = 1;
    bool test = false;
    bool part_1 = true;
    bool part_2 = true;
    bool run_whole_year = false;
    bool run_all = false;

    /// @brief Prints help information and closes the program
    static void help() {
        std::cerr << "Help for AoC solution by Sean Camps \n"
                     "  -h      Prints this helpful message\n"
                     "  -y Y    Specify the year you want to run (Defaults to current year)\n"
                     "  -d D    Specify the day you want to run (Defaults to 1)\n"
                     "  -o      Run part 1\n"
                     "  -t      Run part 2\n"
                     "  -w      Run the whole year\n"
                     "  -a      Run all solutions\n"
                     "  -s      Run with tests\n";
        std::cerr.flush();
        exit(0);
    }

    void run_year_day( int local_year, int local_day) {
        std::cout << "Running year " << local_year << " day " << local_day << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        switch (local_year) {
            case 2015:
                switch (local_day) {
                    case 1:
                        aoc_2015_01(test, part_1, part_2);
                        break;
                    case 2:
                        aoc_2015_02(test, part_1, part_2);
                        break;
                    case 3:
                        aoc_2015_03(test, part_1, part_2);
                        break;
                    case 4:
                        aoc_2015_04(test, part_1, part_2);
                        break;
                    case 5:
                        aoc_2015_05(test, part_1, part_2);
                        break;
                    case 6:
                        aoc_2015_06(test, part_1, part_2);
                        break;
//                    case 7:
//                        aoc_20xx_07(test, part_1, part_2);
//                        break;
//                    case 8:
//                        aoc_20xx_08(test, part_1, part_2);
//                        break;
//                    case 9:
//                        aoc_20xx_09(test, part_1, part_2);
//                        break;
//                    case 10:
//                        aoc_20xx_10(test, part_1, part_2);
//                        break;
//                    case 11:
//                        aoc_20xx_11(test, part_1, part_2);
//                        break;
//                    case 12:
//                        aoc_20xx_12(test, part_1, part_2);
//                        break;
//                    case 13:
//                        aoc_20xx_13(test, part_1, part_2);
//                        break;
//                    case 14:
//                        aoc_20xx_14(test, part_1, part_2);
//                        break;
//                    case 15:
//                        aoc_20xx_15(test, part_1, part_2);
//                        break;
//                    case 16:
//                        aoc_20xx_16(test, part_1, part_2);
//                        break;
//                    case 17:
//                        aoc_20xx_17(test, part_1, part_2);
//                        break;
//                    case 18:
//                        aoc_20xx_18(test, part_1, part_2);
//                        break;
//                    case 19:
//                        aoc_20xx_19(test, part_1, part_2);
//                        break;
//                    case 20:
//                        aoc_20xx_20(test, part_1, part_2);
//                        break;
//                    case 21:
//                        aoc_20xx_21(test, part_1, part_2);
//                        break;
//                    case 22:
//                        aoc_20xx_22(test, part_1, part_2);
//                        break;
//                    case 23:
//                        aoc_20xx_23(test, part_1, part_2);
//                        break;
//                    case 24:
//                        aoc_20xx_24(test, part_1, part_2);
//                        break;
//                    case 25:
//                        aoc_20xx_25(test, part_1, part_2);
//                        break;
                    default:
                        std::cout << "Day " << local_day << " not in range" << std::endl;
                }
                break;
            case 2016:
                switch (local_day) {
                    case 1:
                        aoc_2016_01(test, part_1, part_2);
                        break;
//                    case 2:
//                        aoc_2015_02(test, part_1, part_2);
//                        break;
//                    case 3:
//                        aoc_2015_03(test, part_1, part_2);
//                        break;
//                    case 4:
//                        aoc_2015_04(test, part_1, part_2);
//                        break;
//                    case 5:
//                        aoc_2015_05(test, part_1, part_2);
//                        break;
//                    case 6:
//                        aoc_2015_06(test, part_1, part_2);
//                        break;
//                    case 7:
//                        aoc_20xx_07(test, part_1, part_2);
//                        break;
//                    case 8:
//                        aoc_20xx_08(test, part_1, part_2);
//                        break;
//                    case 9:
//                        aoc_20xx_09(test, part_1, part_2);
//                        break;
//                    case 10:
//                        aoc_20xx_10(test, part_1, part_2);
//                        break;
//                    case 11:
//                        aoc_20xx_11(test, part_1, part_2);
//                        break;
//                    case 12:
//                        aoc_20xx_12(test, part_1, part_2);
//                        break;
//                    case 13:
//                        aoc_20xx_13(test, part_1, part_2);
//                        break;
//                    case 14:
//                        aoc_20xx_14(test, part_1, part_2);
//                        break;
//                    case 15:
//                        aoc_20xx_15(test, part_1, part_2);
//                        break;
//                    case 16:
//                        aoc_20xx_16(test, part_1, part_2);
//                        break;
//                    case 17:
//                        aoc_20xx_17(test, part_1, part_2);
//                        break;
//                    case 18:
//                        aoc_20xx_18(test, part_1, part_2);
//                        break;
//                    case 19:
//                        aoc_20xx_19(test, part_1, part_2);
//                        break;
//                    case 20:
//                        aoc_20xx_20(test, part_1, part_2);
//                        break;
//                    case 21:
//                        aoc_20xx_21(test, part_1, part_2);
//                        break;
//                    case 22:
//                        aoc_20xx_22(test, part_1, part_2);
//                        break;
//                    case 23:
//                        aoc_20xx_23(test, part_1, part_2);
//                        break;
//                    case 24:
//                        aoc_20xx_24(test, part_1, part_2);
//                        break;
//                    case 25:
//                        aoc_20xx_25(test, part_1, part_2);
//                        break;
                    default:
                        std::cout << "Day " << local_day << " not in range" << std::endl;
                }
                break;
            case 2017:
                switch (local_day) {
                    case 1:
                        aoc_2017_01(test, part_1, part_2);
                        break;
//                    case 2:
//                        aoc_2015_02(test, part_1, part_2);
//                        break;
//                    case 3:
//                        aoc_2015_03(test, part_1, part_2);
//                        break;
//                    case 4:
//                        aoc_2015_04(test, part_1, part_2);
//                        break;
//                    case 5:
//                        aoc_2015_05(test, part_1, part_2);
//                        break;
//                    case 6:
//                        aoc_2015_06(test, part_1, part_2);
//                        break;
//                    case 7:
//                        aoc_20xx_07(test, part_1, part_2);
//                        break;
//                    case 8:
//                        aoc_20xx_08(test, part_1, part_2);
//                        break;
//                    case 9:
//                        aoc_20xx_09(test, part_1, part_2);
//                        break;
//                    case 10:
//                        aoc_20xx_10(test, part_1, part_2);
//                        break;
//                    case 11:
//                        aoc_20xx_11(test, part_1, part_2);
//                        break;
//                    case 12:
//                        aoc_20xx_12(test, part_1, part_2);
//                        break;
//                    case 13:
//                        aoc_20xx_13(test, part_1, part_2);
//                        break;
//                    case 14:
//                        aoc_20xx_14(test, part_1, part_2);
//                        break;
//                    case 15:
//                        aoc_20xx_15(test, part_1, part_2);
//                        break;
//                    case 16:
//                        aoc_20xx_16(test, part_1, part_2);
//                        break;
//                    case 17:
//                        aoc_20xx_17(test, part_1, part_2);
//                        break;
//                    case 18:
//                        aoc_20xx_18(test, part_1, part_2);
//                        break;
//                    case 19:
//                        aoc_20xx_19(test, part_1, part_2);
//                        break;
//                    case 20:
//                        aoc_20xx_20(test, part_1, part_2);
//                        break;
//                    case 21:
//                        aoc_20xx_21(test, part_1, part_2);
//                        break;
//                    case 22:
//                        aoc_20xx_22(test, part_1, part_2);
//                        break;
//                    case 23:
//                        aoc_20xx_23(test, part_1, part_2);
//                        break;
//                    case 24:
//                        aoc_20xx_24(test, part_1, part_2);
//                        break;
//                    case 25:
//                        aoc_20xx_25(test, part_1, part_2);
//                        break;
                    default:
                        std::cout << "Day " << local_day << " not in range" << std::endl;
                }
                break;
            case 2018:
                switch (local_day) {
                    case 1:
                        aoc_2018_01(test, part_1, part_2);
                        break;
//                    case 2:
//                        aoc_2015_02(test, part_1, part_2);
//                        break;
//                    case 3:
//                        aoc_2015_03(test, part_1, part_2);
//                        break;
//                    case 4:
//                        aoc_2015_04(test, part_1, part_2);
//                        break;
//                    case 5:
//                        aoc_2015_05(test, part_1, part_2);
//                        break;
//                    case 6:
//                        aoc_2015_06(test, part_1, part_2);
//                        break;
//                    case 7:
//                        aoc_20xx_07(test, part_1, part_2);
//                        break;
//                    case 8:
//                        aoc_20xx_08(test, part_1, part_2);
//                        break;
//                    case 9:
//                        aoc_20xx_09(test, part_1, part_2);
//                        break;
//                    case 10:
//                        aoc_20xx_10(test, part_1, part_2);
//                        break;
//                    case 11:
//                        aoc_20xx_11(test, part_1, part_2);
//                        break;
//                    case 12:
//                        aoc_20xx_12(test, part_1, part_2);
//                        break;
//                    case 13:
//                        aoc_20xx_13(test, part_1, part_2);
//                        break;
//                    case 14:
//                        aoc_20xx_14(test, part_1, part_2);
//                        break;
//                    case 15:
//                        aoc_20xx_15(test, part_1, part_2);
//                        break;
//                    case 16:
//                        aoc_20xx_16(test, part_1, part_2);
//                        break;
//                    case 17:
//                        aoc_20xx_17(test, part_1, part_2);
//                        break;
//                    case 18:
//                        aoc_20xx_18(test, part_1, part_2);
//                        break;
//                    case 19:
//                        aoc_20xx_19(test, part_1, part_2);
//                        break;
//                    case 20:
//                        aoc_20xx_20(test, part_1, part_2);
//                        break;
//                    case 21:
//                        aoc_20xx_21(test, part_1, part_2);
//                        break;
//                    case 22:
//                        aoc_20xx_22(test, part_1, part_2);
//                        break;
//                    case 23:
//                        aoc_20xx_23(test, part_1, part_2);
//                        break;
//                    case 24:
//                        aoc_20xx_24(test, part_1, part_2);
//                        break;
//                    case 25:
//                        aoc_20xx_25(test, part_1, part_2);
//                        break;
                    default:
                        std::cout << "Day " << local_day << " not in range" << std::endl;
                }
                break;
            case 2022:
                switch (local_day) {
                    case 1:
                        aoc_2022_01(test, part_1, part_2);
                        break;
                    case 2:
                        aoc_2022_02(test, part_1, part_2);
                        break;
                    case 3:
                        aoc_2022_03(test, part_1, part_2);
                        break;
                    case 4:
                        aoc_2022_04(test, part_1, part_2);
                        break;
                    case 5:
                        aoc_2022_05(test, part_1, part_2);
                        break;
                    case 6:
                        aoc_2022_06(test, part_1, part_2);
                        break;
                    case 7:
                        aoc_2022_07(test, part_1, part_2);
                        break;
                    case 8:
                        aoc_2022_08(test, part_1, part_2);
                        break;
                    case 9:
                        aoc_2022_09(test, part_1, part_2);
                        break;
                    case 10:
                        aoc_2022_10(test, part_1, part_2);
                        break;
                    case 11:
                        aoc_2022_11(test, part_1, part_2);
                        break;
//                    case 12:
//                        aoc_20xx_12(test, part_1, part_2);
//                        break;
//                    case 13:
//                        aoc_20xx_13(test, part_1, part_2);
//                        break;
//                    case 14:
//                        aoc_20xx_14(test, part_1, part_2);
//                        break;
//                    case 15:
//                        aoc_20xx_15(test, part_1, part_2);
//                        break;
//                    case 16:
//                        aoc_20xx_16(test, part_1, part_2);
//                        break;
//                    case 17:
//                        aoc_20xx_17(test, part_1, part_2);
//                        break;
//                    case 18:
//                        aoc_20xx_18(test, part_1, part_2);
//                        break;
//                    case 19:
//                        aoc_20xx_19(test, part_1, part_2);
//                        break;
//                    case 20:
//                        aoc_20xx_20(test, part_1, part_2);
//                        break;
//                    case 21:
//                        aoc_20xx_21(test, part_1, part_2);
//                        break;
//                    case 22:
//                        aoc_20xx_22(test, part_1, part_2);
//                        break;
//                    case 23:
//                        aoc_20xx_23(test, part_1, part_2);
//                        break;
//                    case 24:
//                        aoc_20xx_24(test, part_1, part_2);
//                        break;
//                    case 25:
//                        aoc_20xx_25(test, part_1, part_2);
//                        break;
                    default:
                        std::cout << "Day " << local_day << " not in range" << std::endl;
                    }
                    break;
            default:
                std::cout << "Year " << local_year << " not implemented" << std::endl;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time = end - start;
        std::cout << time.count() << "ms" << std::endl;
    }

    /// @brief Run the program with current options
    void run() {
        if (run_all) {
            for (int i = 2015; i <= MAX_YEAR; i++){
                for (int j = 1; j < 26; j++) {
                    run_year_day(i, j);
                }
            }
        }
        else if (run_whole_year) {
            for (int j = 1; j < 26; j++) {
                run_year_day(year, j);
            }
        }
        else {
            run_year_day(year, day);
        }
    }
};

int main(int argc, char *argv[]) {

    ProgramOptions po;

    // Use GNU getopt to parse command line options
    int opt;
    while ((opt = getopt(argc, argv, "hy:d:otwas")) != -1) {
        switch (opt) {

            case 'h': {
                ProgramOptions::help();
                break;
            }

            case 'y': {
                po.year = std::stoi(optarg);
                break;
            }

            case 'd': {
                po.day = std::stoi(optarg);
                break;
            }

            case 'o': {
                po.part_1 = true;
                break;
            }

            case 't': {
                po.part_2 = true;
                break;
            }

            case 'w': {
                po.run_whole_year = true;
                break;
            }

            case 'a': {
                po.run_all = true;
                break;
            }

            case 's': {
                po.test = true;
                break;
            }

            default: {
                std::cerr << "Some invalid option was supplied." << std::endl;
                ProgramOptions::help();
                break;
            }
        }
    }

    po.run();

    return 0;
}