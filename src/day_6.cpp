#include "day_6.hpp"
#include "util.hpp"
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

map<int, long> create_fish_map(vector<long>&& fish);
long calculate_population(int days, map<int, long> &&fish_map);

namespace day_6
{
    long get_solution_1()
    {
        auto input = parse_lines("../data/day_6.txt");
        auto fish_string = split_string(input[0], ",");
        vector<long> fish;
        for_each(fish_string.begin(), fish_string.end(), [&fish](auto f) { fish.push_back(stoi(f)); });
        auto m = create_fish_map(std::move(fish));
        return calculate_population(256, std::move(m));
    }
}

map<int, long> create_fish_map(vector<long>&& fish)
{
    map<int, long> m = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, 
                         {4, 0}, {5, 0}, {6, 0}, {7, 0}, 
                         {8, 0} };
    
    for (auto f : fish)
        m[f] += 1;
    
    return m;
}

long calculate_population(int days, map<int, long> &&fish_map)
{
    for (auto day = 0; day < days; ++day)
    {
        auto new_fish = fish_map[0];

        for (int i = 0; i < 8; ++i)
            fish_map[i] = fish_map[i + 1];
        
        fish_map[6] += new_fish;
        fish_map[8] = new_fish;
    }

    long count = 0;
    for (auto [_, v] : fish_map)
        count += v;

    return count;
}
