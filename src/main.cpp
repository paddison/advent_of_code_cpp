#include "day_8.hpp"
#include "util.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

void test_split();

int main() 
{
    auto solution = day_8::get_solution_1();
    cout << "solution is: " << solution << "\n";
    return 0;
}

void test_split()
{
    vector<string> result = split_string("1,2,3,,4,,5,,", ",,");
    for (auto r : result)
    {
        cout << r << "\n";
    }
}