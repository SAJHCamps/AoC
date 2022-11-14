cmake_minimum_required(VERSION 3.23)
project(AoC)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

set(STANDARD_SRC
        src/main.cpp)

set(SRC_2015
        src/2015/aoc_2015_01.cpp src/2015/aoc_2015_01.hpp
        src/2015/aoc_2015_02.cpp src/2015/aoc_2015_02.hpp)

add_executable(${PROJECT_NAME} ${STANDARD_SRC} ${SRC_2015})
