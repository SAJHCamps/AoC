cmake_minimum_required(VERSION 3.23)
project(AoC)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

set(STANDARD_SRC
        src/main.cpp)

set(SRC_2015
        src/2015/aoc_2015_01.cpp src/2015/aoc_2015_01.hpp
        src/2015/aoc_2015_02.cpp src/2015/aoc_2015_02.hpp
        src/2015/aoc_2015_03.cpp src/2015/aoc_2015_03.hpp
        src/2015/aoc_2015_04.cpp src/2015/aoc_2015_04.hpp
        src/2015/aoc_2015_05.cpp src/2015/aoc_2015_05.hpp
        src/2015/aoc_2015_06.cpp src/2015/aoc_2015_06.hpp)

set(SRC_2016
        src/2016/aoc_2016_01.cpp src/2016/aoc_2016_01.hpp)

set(SRC_2017
        src/2017/aoc_2017_01.cpp src/2017/aoc_2017_01.hpp)

set(SRC_2022
        src/2022/aoc_2022_01.cpp src/2022/aoc_2022_01.hpp
        src/2022/aoc_2022_02.cpp src/2022/aoc_2022_02.hpp
        src/2022/aoc_2022_03.cpp src/2022/aoc_2022_03.hpp
        src/2022/aoc_2022_04.cpp src/2022/aoc_2022_04.hpp
        src/2022/aoc_2022_05.cpp src/2022/aoc_2022_05.hpp
        src/2022/aoc_2022_06.cpp src/2022/aoc_2022_06.hpp
        src/2022/aoc_2022_07.cpp src/2022/aoc_2022_07.hpp
        src/2022/aoc_2022_08.cpp src/2022/aoc_2022_08.hpp
        src/2022/aoc_2022_09.cpp src/2022/aoc_2022_09.hpp
        src/2022/aoc_2022_10.cpp src/2022/aoc_2022_10.hpp
        src/2022/aoc_2022_11.cpp src/2022/aoc_2022_11.hpp)

#OpenSSl for 2015 day 4
find_package(OpenSSL REQUIRED)

add_executable(${PROJECT_NAME} ${STANDARD_SRC} ${SRC_2015} ${SRC_2016} ${SRC_2017} ${SRC_2022})

#OpenSSL for 2015 day 4
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
