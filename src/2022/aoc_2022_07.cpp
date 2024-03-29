#include "aoc_2022_07.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

struct file_tree {
    bool is_dir;
    int size;
    std::string name;
    struct file_tree *parent;
    std::vector<struct file_tree*> children;
};

void set_sizes_file_tree(struct file_tree* start) {
    if (start->is_dir) {
        int total_size = 0;
        for (auto i: start->children){
            set_sizes_file_tree(i);
            total_size += i->size;
        }
        start->size = total_size;
    }
}

int check_sizes_file_tree_part_1(struct file_tree* start) {
    if (start->is_dir) {
        int sum = 0;
        if (start->size < 100000) {
            sum += start->size;
        }
        for (auto i: start->children) {
            sum += check_sizes_file_tree_part_1(i);
        }
        return sum;
    }
    else {
        return 0;
    }
}

void run_2022_7_part_1(bool test) {
    std::ifstream file;
    std::cout << "Part 1 day 7" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_7_1.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_7.txt");
    }
    std::string input;
    auto root = new struct file_tree;
    root->name = "/";
    root->parent = nullptr;
    root->is_dir = true;
    root->size = -1;
    struct file_tree *current;
    current = root;
    while (std::getline(file, input)) {
        if (input[0] != '$') {
            auto new_file = new struct file_tree;
            new_file->parent = current;
            new_file->children = {};
            if (input[0] >= '0' && input[0] <= '9') {
                int begin_name = input.find_first_not_of("0123456789");
                new_file->size = std::stoi(input.substr(0, begin_name));
                new_file->name = input.substr(begin_name + 1, std::string::npos);
                new_file->is_dir = false;
            } else {
                new_file->size = -1;
                new_file->name = input.substr(4, std::string::npos);
                new_file->is_dir = true;
            }
            current->children.push_back(new_file);
        } else {
            if (input[2] == 'c') {
                if (input[5] == '.') {
                    current = current->parent;
                } else if (input[5] == '/') {
                    current = root;
                } else {
                    for (auto i: current->children) {
                        if (i->is_dir && i->name == input.substr(5, std::string::npos)) {
                            current = i;
                            break;
                        }
                    }
                }
            }
        }
    }
    set_sizes_file_tree(root);

    std::cout << check_sizes_file_tree_part_1(root) << std::endl;
    file.close();
}

int check_sizes_file_tree_part_2(struct file_tree* start, int to_free) {
    if (start->is_dir) {
        int smallest = std::numeric_limits<int>::max();
        if (start->size > to_free) {
            smallest = start->size;
        }
        for (auto i: start->children) {
            smallest = std::min(smallest, check_sizes_file_tree_part_2(i, to_free));
        }
        return smallest;
    }
    else {
        return std::numeric_limits<int>::max();
    }
}

void run_2022_7_part_2(bool test) {
    std::ifstream file;
    std::cout << "Part 2 day 7" << std::endl;
    if (test) {
        file.open("../src/2022/test/test_7_2.txt");
        std::string answer;
        std::getline(file,answer);
        std::cout << "Test should give: " << answer << std::endl;
    }
    else {
        file.open("../src/2022/input/day_7.txt");
    }
    std::string input;
    auto root = new struct file_tree;
    root->name = "/";
    root->parent = nullptr;
    root->is_dir = true;
    root->size = -1;
    struct file_tree *current;
    current = root;
    while (std::getline(file, input)) {
        if (input[0] != '$') {
            auto new_file = new struct file_tree;
            new_file->parent = current;
            new_file->children = {};
            if (input[0] >= '0' && input[0] <= '9') {
                int begin_name = input.find_first_not_of("0123456789");
                new_file->size = std::stoi(input.substr(0, begin_name));
                new_file->name = input.substr(begin_name + 1, std::string::npos);
                new_file->is_dir = false;
            } else {
                new_file->size = -1;
                new_file->name = input.substr(4, std::string::npos);
                new_file->is_dir = true;
            }
            current->children.push_back(new_file);
        } else {
            if (input[2] == 'c') {
                if (input[5] == '.') {
                    current = current->parent;
                } else if (input[5] == '/') {
                    current = root;
                } else {
                    for (auto i: current->children) {
                        if (i->is_dir && i->name == input.substr(5, std::string::npos)) {
                            current = i;
                            break;
                        }
                    }
                }
            }
        }
    }
    set_sizes_file_tree(root);

    std::cout << check_sizes_file_tree_part_2(root,  root->size - 40000000) << std::endl;
    file.close();
}


void aoc_2022_07(bool test,bool part_1, bool part_2) {
    if (part_1) {
        run_2022_7_part_1(test);
    }
    if (part_2) {
        run_2022_7_part_2(test);
    }
}