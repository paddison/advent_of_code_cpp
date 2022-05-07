#include "day_4.hpp"
#include "util.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;
using namespace day_4;

vector<Board> parse_boards(vector<string> &&input);

namespace day_4
{
    int get_solution_1()
    {
        auto input = parse_lines("../data/day_4.txt");
        auto numbers = map_to_int(split_string(input[0], ","));
        auto boards = parse_boards(std::move(input));
        for (auto n : numbers)
        {
            for (Board& board : boards)
            {
                auto point = board.contains_number(n);
                if (point.has_value())
                {
                    board.mark(point.value().row, point.value().col);
                    if (board.is_winner())
                    {
                        return board.calculate_score(n);
                    }
                }
            }
        }
        return 0;
    }

    int get_solution_2()
    {
        auto input = parse_lines("../data/day_4.txt");
        auto numbers = map_to_int(split_string(input[0], ","));
        auto boards = parse_boards(std::move(input));
        set<int> winners;
        for (auto n : numbers)
        {
            for (int i = 0; i < boards.size(); ++i)
            {
                if (winners.find(i) != winners.end())
                    continue;
                auto point = boards[i].contains_number(n);
                if (point.has_value())
                {
                    boards[i].mark(point.value().row, point.value().col);
                    if (boards[i].is_winner())
                    {
                        winners.insert(i);
                        if (winners.size() == boards.size())
                        {
                            return boards[i].calculate_score(n);
                        }
                    }
                }
            }
        }
        return false;
    }

    void test_board()
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
        day_4::Board board(v);
        board.mark(0, 0);
        board.mark(0, 1);
        board.mark(0, 2);
        board.mark(0, 3);
        board.mark(4, 4);
        cout << board.is_winner() << "\n";
    }
}

vector<Board> parse_boards(vector<string> &&input)
{
    vector<Board> boards;
    vector<int> values;

    for (auto i = 1; i < input.size(); ++i)
    {
        vector<string> line = split_string(input[i], " ");
        if (line.size() != 0)
        {
            for_each(line.begin(), line.end(), [&values](string n) { values.push_back(stoi(n)); });
        }
       
        if (i % 6 == 0)
        {
            boards.push_back(Board(values));
            values.clear();
        }
    }
    return boards;
}

// Board Implementations
Board::Board(vector<int> vals)
{
    values = vals;
}

inline int Board::get(int row, int column)
{
    return values[row * 5 + column] % Board::mask;
}

void Board::mark(int row, int column)
{
    int& ref_value = values[row * 5 + column];
    ref_value = ref_value | Board::mask; 
}

optional<Point> Board::contains_number(int n)
{
    for (auto row = 0; row < 5; ++row)
    {
        for (auto col = 0; col < 5; ++col)
        {
            if (values[row * 5 + col] == n)
            {
                return optional<Point> { Point(row, col)};
            }
        }
    }
    return nullopt;
}
            
bool Board::is_winner()
{
    // check rows
    bool won = true;
    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if (!this->is_marked(i, j))
            {
                won = false;
            }
        }
        if (won)
        {
            return true;
        }
        won = true;
    }

    // check columns
    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if (!this->is_marked(j, i))
            {
                won = false;
            }
        }
        if (won)
        {
            return true;
        }
        won = true;
    }

    return false;
}

inline bool Board::is_marked(int row, int column)
{
    return (values[row * 5 + column] & Board::mask) != 0;
}

int Board::calculate_score(int n)
{
    auto sum = 0;
    for (auto val : values)
    {
        if ((val & Board::mask) == 0)
        {
            sum += val;
        }
    }

    return sum * n;
}

// Point Helper Struct implementation
Point::Point(int row, int col)
{
    this->row = row;
    this->col = col;
}