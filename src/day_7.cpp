#include <vector>
#include <string>
#include <iostream>
#include "util.hpp"

int brute_force_fuel(const vector<int>&&);
int brute_force_fuel_2(const vector<int>&&);
int max(const vector<int>&);

namespace day_7
{
    int get_solution_1()
    {
        const string line = parse_lines("../data/day_7.txt")[0];
        const vector<string> number_strings = split_string(line, ",");
        vector<int> numbers;
        for_each(number_strings.begin(), number_strings.end(), [&numbers](auto n) { numbers.push_back(stoi(n)); });
        return brute_force_fuel(std::move(numbers));
    }

    int get_solution_2()
    {
        const string line = parse_lines("../data/day_7.txt")[0];
        const vector<string> number_strings = split_string(line, ",");
        vector<int> numbers;
        for_each(number_strings.begin(), number_strings.end(), [&numbers](auto n) { numbers.push_back(stoi(n)); });
        return brute_force_fuel_2(std::move(numbers));
    }
}

int brute_force_fuel(const vector<int>&& numbers) 
{
    int max_n = max(numbers);
    int min_fuel = INT_MAX;
    for (; max_n > 0; --max_n)
    {
        int sum = 0;
        for (const auto n : numbers)
        {
            sum += abs(n - max_n);
        }
        if (sum < min_fuel)
            min_fuel = sum;
    }

    return min_fuel;
}

int brute_force_fuel_2(const vector<int>&& numbers) 
{
    int max_n = max(numbers);
    int min_fuel = INT_MAX;
    for (; max_n > 0; --max_n)
    {
        int sum = 0;
        for (const auto n : numbers)
        {
            int diff = abs(n - max_n); 
            sum += diff * (diff + 1) / 2;
        }
        if (sum < min_fuel)
            min_fuel = sum;
    }

    return min_fuel;
}

int max(const vector<int>& numbers)
{
    int max = 0;
    for (auto n : numbers)
    {
        if (n > max) 
            max = n;
    }

    return max;
}

