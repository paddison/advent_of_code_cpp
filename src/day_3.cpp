#include "day_3.hpp"
#include "util.hpp"
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int common_bit(const vector<string>& lines, const int index, const bool is_oxy);
int determine_rating(vector<string> values, const bool is_oxy);
int bit_string_to_int(const string input);

namespace day_3
{
    int get_solution_1()
    {
        auto lines = parse_lines("../data/day_3.txt");
        unsigned int gamma_rate = 0;
        unsigned int mask = pow(2, lines[0].size()) - 1;

        for (auto i = 0; i < lines[0].size(); ++i)
        {
            auto bit = common_bit(lines, i, false);
            gamma_rate += pow(2 * bit, lines[0].size() - 1 - i);
        }

        return gamma_rate * (~gamma_rate & mask);
    }

    int get_solution_2()
    {
        auto oxy_gen_values = parse_lines("../data/day_3.txt");
        auto co2_scrub_values = oxy_gen_values;

        auto oxy_gen_rating = determine_rating(std::move(oxy_gen_values), true);
        auto co2_scrub_rating = determine_rating(std::move(co2_scrub_values), false);
        
        return oxy_gen_rating * co2_scrub_rating;
    }
}

int common_bit(const vector<string>& lines, int index, const bool is_oxy)
{
    auto count_ones = 0;
    auto size = lines.size();
    for (auto line : lines)
    {
        if (line[index] == '1')
        {
            count_ones += 1;
        }
    }

    if (count_ones * 2 >= size)
    {
        return 1;
    } 
    else
    {
        return 0;
    }
}

int determine_rating(vector<string> values, const bool is_oxy)
{
    vector<string> tmp;
    auto i = 0;

    while (values.size() != 1)
        {
            auto bit = common_bit(values, i, is_oxy);
            for (auto line : values)
            {
                if (line[i] == bit + 48 && is_oxy)
                {
                    tmp.push_back(line);
                }
                else if (line[i] != bit + 48 && !is_oxy)
                {
                    tmp.push_back(line);
                }
            }

            values = std::move(tmp);
            vector<string> tmp;
            ++i;
        }
    
    return bit_string_to_int(values[0]);
}

int bit_string_to_int(const string input)
{
    auto n = 0;
    auto exp = input.size() - 1;
    for (auto i = 0; i < input.size(); ++i)
    {
        if (input[i] == '1')
        {
            n += pow(2, exp);
        }
        --exp;
    }

    return n;
}