#include "day_5/day_5.hpp"
#include "day_5/line.hpp"
#include "util.hpp"
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

using Point = std::pair<int, int>;
using LineMap = std::map<Point, int>;

int get_solution_1()
{
    auto input = parse_lines("/Users/patrickbaumann/Documents/hdm/4/cpp/stuff/advent_of_code/data/day_5.txt");
    vector<Line> lines;
    for (auto line : input)
    {
        auto point_strings = split_string(line, "->");
        auto start_string = split_string(point_strings[0], ",");
        auto end_string = split_string(point_strings[1], ",");
        Point start = std::pair(stoi(start_string[0]), stoi(start_string[1]));
        Point end = std::pair(stoi(end_string[0]), stoi(end_string[1]));
        lines.push_back(Line(start, end));
    }  
    vector<Line> filtered;
    for_each(lines.begin(), lines.end(), [&filtered](Line line) { 
        if (!line.is_diag())
            filtered.push_back(line);        
        });

    LineMap m;

    for (Line l : filtered)
    {
        for (auto p : l)
        {
            auto item = m.find(p);
            if (item != m.end())
                m[p] += 1;
            else 
                m[p] = 1;
        }
    }
    auto count = 0;
    for (auto [key, val] : m)
    {
        if (val >= 2)
            ++count;
    }

    return count;
}

int get_solution_2()
{
    auto input = parse_lines("/Users/patrickbaumann/Documents/hdm/4/cpp/stuff/advent_of_code/data/day_5.txt");
    vector<Line> lines;
    for (auto line : input)
    {
        auto point_strings = split_string(line, "->");
        auto start_string = split_string(point_strings[0], ",");
        auto end_string = split_string(point_strings[1], ",");
        Point start = std::pair(stoi(start_string[0]), stoi(start_string[1]));
        Point end = std::pair(stoi(end_string[0]), stoi(end_string[1]));
        lines.push_back(Line(start, end));
    }  

    LineMap m;

    for (Line l : lines)
    {
        for (auto p : l)
        {
            auto item = m.find(p);
            if (item != m.end())
                m[p] += 1;
            else 
                m[p] = 1;
        }
    }
    auto count = 0;
    for (auto [key, val] : m)
    {
        if (val >= 2)
            ++count;
    }

    return count;
}