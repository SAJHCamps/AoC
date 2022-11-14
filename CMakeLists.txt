cmake_minimum_required(VERSION 3.23)
project(AoC)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

set(STANDARD_SRC
        src/main.cpp)

set(TEMPLATE_SRC
        src/Template/aoc_20xx_01.cpp src/Template/aoc_20xx_01.hpp)

add_executable(${PROJECT_NAME} ${STANDARD_SRC} ${TEMPLATE_SRC})
