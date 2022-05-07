#include "day_5/day_5.hpp"
#include "day_5/line.hpp"
#include "util.hpp"
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>

using Point = std::pair<int, int>;

Line::Line(Point start_v, Point end_v)
{
    start_p = start_v;
    end_p = end_v;
    if (start_v.first < end_v.first && start_v.second == end_v.second)
        dir = Direction::right;
    else if (start_v.first > end_v.first && start_v.second == end_v.second)
        dir = Direction::left;
    else if (start_v.first == end_v.first && start_v.second < end_v.second)
        dir = Direction::down;
    else if (start_v.first == end_v.first && start_v.second > end_v.second)
        dir = Direction::up;
    else if (start_v.first > end_v.first && start_v.second > end_v.second)
        dir = Direction::up_left;
    else if (start_v.first < end_v.first && start_v.second > end_v.second)
        dir = Direction::up_right;
    else if (start_v.first > end_v.first && start_v.second < end_v.second)
        dir = Direction::down_left;
    else if (start_v.first < end_v.first && start_v.second < end_v.second)
        dir = Direction::down_right;
}

bool Line::walk()
{
    if (start_p.first == end_p.first && start_p.second == end_p.second)
        return false;
    
    // determine if to walk horizontally or vertically
    if (start_p.first == end_p.first)
    {      
        if (start_p.second < end_p.second) // walk horizontally
            start_p.second += 1;
        else    
            start_p.second -= 1;
    }
    else 
    {
        if (start_p.first < end_p.first)  // walk vertically
            start_p.first += 1;
        else
            start_p.first -= 1;
    }

    return true;
}

bool Line::walk_diag()
{
    return false;
}

bool Line::is_diag()
{
    return dir != Direction::up && dir != Direction::down && dir != Direction::left && dir != Direction::right;
}

LineIterator Line::begin()
{
    return LineIterator(start_p, dir);
}

LineIterator Line::end()
{
    Point end;
    switch(dir)
    {
        case up: end = Point(end_p.first, end_p.second - 1); break;
        case down: end = Point(end_p.first, end_p.second + 1); break;
        case Direction::left: end = Point(end_p.first - 1, end_p.second); break;
        case Direction::right: end = Point(end_p.first + 1, end_p.second); break;
        case Direction::up_left: end = Point(end_p.first - 1, end_p.second - 1); break;
        case Direction::up_right: end = Point(end_p.first + 1, end_p.second - 1); break;
        case Direction::down_left: end = Point(end_p.first - 1, end_p.second + 1); break;
        case Direction::down_right: end = Point(end_p.first + 1, end_p.second + 1); break;
    }
    return LineIterator(end, dir);
}

// Iterator Implementation
LineIterator::LineIterator(Point p, Direction dir_v)
{
    ptr = p;
    dir = dir_v;
}

LineIterator& LineIterator::operator++()
{
    switch(dir)
    {
        case up: ptr.second -= 1; break;
        case down: ptr.second += 1; break;
        case Direction::left:  ptr.first -= 1; break;
        case Direction::right: ptr.first += 1; break;
        case Direction::up_left: ptr.first -= 1; ptr.second -= 1; break;
        case Direction::up_right: ptr.first += 1; ptr.second -= 1; break;
        case Direction::down_left: ptr.first -= 1; ptr.second += 1; break;
        case Direction::down_right: ptr.first += 1; ptr.second += 1; break;
    }
    return *this;
}

LineIterator& LineIterator::operator++(int)
{
    LineIterator iterator = *this;
    ++(*this);
    return iterator;
}

LineIterator& LineIterator::operator--()
{
    switch(dir)
    {
        case up: ptr.second += 1; break;
        case down: ptr.second -= 1; break;
        case Direction::left:  ptr.first += 1; break;
        case Direction::right: ptr.first -= 1; break;
        case Direction::up_left: ptr.first += 1; ptr.second += 1; break;
        case Direction::up_right: ptr.first -= 1; ptr.second += 1; break;
        case Direction::down_left: ptr.first += 1; ptr.second -= 1; break;
        case Direction::down_right: ptr.first -= 1; ptr.second -= 1; break;
    }
    return *this;
}

LineIterator& LineIterator::operator--(int)
{
    LineIterator iterator = *this;
    ++(*this);
    return iterator;
}

bool LineIterator::operator==(const LineIterator& other) const
{
    return (ptr.first == other.ptr.first && ptr.second == other.ptr.second);
}

bool LineIterator::operator!=(const LineIterator& other) const
{
    return !(ptr.first == other.ptr.first && ptr.second == other.ptr.second);
}

LineIterator::PointerType LineIterator::operator*()
{
    return ptr;
}