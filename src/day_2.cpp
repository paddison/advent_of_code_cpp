#include "day_2.hpp"
#include "util.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<char, int> create_map(const vector<string> lines);
int calculate_result(const map<char, int>);
int calculate_result_2(const vector<string> lines);

namespace day_2
{
    int get_solution_1()
    {
        auto lines = parse_lines("../data/day_2.txt");
        auto map = create_map(lines);
        return calculate_result(map);
    }

    int get_solution_2()
    {
        auto lines = parse_lines("../data/day_2.txt");
        return calculate_result_2(lines);
    }
}

map<char, int> create_map(const vector<string> lines)
{
    map<char, int> m = { {'f', 0}, {'u', 0}, {'d', 0} };

    for (auto line : lines)
    {
        auto n = stoi(line.substr(line.size() - 1));

        if (line.find("forward") != string::npos)
        {
            m['f'] += n;
        } 
        else if (line.find("up") != string::npos)
        {
            m['u'] += n;
        }
        else 
        {
            m['d'] += n;
        }
    }

    return m;
}

int calculate_result(const map<char, int> m)
{
    auto depth = m.find('d')->second - m.find('u')->second;
    auto horizontal_pos = m.find('f')->second;

    return depth * horizontal_pos;
}

int calculate_result_2(const vector<string> lines)
{
    int aim, forward, depth;
    aim = forward = depth = 0;

    for (auto line : lines)
    {
        auto n = stoi(line.substr(line.size() - 1));
         if (line.find("forward") != string::npos)
        {
            forward += n;
            depth += n * aim;
        } 
        else if (line.find("up") != string::npos)
        {
            aim -= n;
        }
        else 
        {
            aim += n;
        }
    }

    return forward * depth;
}

