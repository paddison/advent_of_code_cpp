#include "util.hpp"
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <set>

uint32_t determine_unique(const vector<string>&);
void create_wire_map(const vector<string>&&);
set<char> string_to_set(string&& s);

namespace day_8
{
    uint32_t get_solution_1()
    {
        auto lines = parse_lines("../data/day_8.txt");
        vector<vector<string>> data_strings;
        vector<vector<string>> digits;
        vector<vector<string>> numbers;
        for_each(lines.begin(), lines.end(), [&data_strings](auto l) { data_strings.push_back(split_string(l, "|")); });
        for (vector<string> entry : std::move(data_strings))
        {
            digits.push_back(split_string(std::move(entry[0]), " "));
            numbers.push_back(split_string(std::move(entry[1]), " "));
        }

        for (vector<string> digit : std::move(digits))
        {
            for (string s : digit)
            {
                set<char> chars = string_to_set(std::move(s));
                std::cout << &chars << std::endl;
            }

        }

        return 5;
    }
}

uint32_t determine_unique(const vector<string>& number)
{
    uint32_t sum = 0;
    for (string digit : number)
    {
        size_t size = digit.size();
        if (size == 2 || size == 3 || size == 4 || size == 7)
            ++sum;
    }

    return sum;
}

void create_wire_map(const vector<string>&& digits )
{
    // The wires will be numbered in the following way:
    //
    //   (1)
    // (2) (3)
    //   (4)
    // (5) (6)
    //   (7) 
    // 
    
}

set<char> string_to_set(string&& s)
{
    set<char> digit;
    
    for (char c : s)
        digit.insert(c);

    return digit;
}