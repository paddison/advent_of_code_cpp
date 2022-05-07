#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "util.hpp"

using namespace std;

vector<int> parse_file(string file_name) 
{
    string line;
    ifstream file(file_name);
    vector<int> v;

    if (file.is_open()) 
    {
        while(getline(file, line)) 
        {
            v.push_back(stoi(line));
        }
    }
    else 
    {
        cout << "cannot open file: " << file_name << "\n"; 
    }

    return v;
}

vector<string> parse_lines(string file_name)
{
    string line;
    ifstream file(file_name);
    vector<string> v;

    if (file.is_open()) 
    {
        while(getline(file, line)) 
        {
            v.push_back(line);
        }
    }
    else 
    {
        cout << "cannot open file: " << file_name << "\n"; 
    }

    return v;
}

vector<string> split_string(string input, const string delimiter)
{
    trim(input);
    vector<string> result;
    string substr;
    auto pos = 0;
    while ((pos = input.find(delimiter)) != string::npos)
    {
        if (pos != 0)
        {
            result.push_back(input.substr(0, pos));
        }
        input.erase(0, pos + delimiter.length());
    }
    if (input.size() > 0)
    {
        result.push_back(input);
    }

    return result;
}

void ltrim(string &s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int c) { return !isspace(c); }));
}

void rtrim(string &s)
{
    s.erase(find_if(s.rbegin(), s.rend(), [](int c) { return !isspace(c); }).base(), s.end());
}

void trim(string &s)
{
    ltrim(s);
    rtrim(s);
}

vector<int> map_to_int(vector<string> input)
{
    vector<int> numbers;
    for (string n : input)
    {
        numbers.push_back(stoi(n));
    }
    return numbers;
}