#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "util.hpp"

using namespace std;

// part one
int count_increases(const vector<int> input);

// part two
int count_increases_2(const vector<int> input);
int get_window_sum(const int* const ptr);

namespace day_1
{
    int get_solution_1() 
    {
        auto input = parse_file("../data/day_1.txt");

        return count_increases(input);
    }

    int get_solution_2()
    {
        auto input = parse_file("../data/day_1.txt");

        return count_increases_2(input);
    }

}

int count_increases(const vector<int> input)
{
    auto count = 0;
    for (auto i = 1; i < input.size(); ++i)
    {
        if (input[i] > input[i - 1])
        {
            ++count;
        }
    }

    return count;
}

// part two
int count_increases_2(const vector<int> input)
{
    auto count = 0;
    for (auto i = 0; i < input.size() - 2; ++i)
    {
        auto sum_1 = get_window_sum(&input[i]);
        auto sum_2 = get_window_sum(&input[i + 1]);
        if (sum_2 > sum_1)
        {
            ++count;
        }
    }

    return count;
}

int get_window_sum(const int* const ptr ) 
{
    // ptr = nullptr;
    return *ptr + *(ptr + 1) + *(ptr + 2);
}