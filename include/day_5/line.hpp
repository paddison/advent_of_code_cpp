#include <tuple>

enum Direction { up, down, left, right, up_left, down_left, up_right, down_right };

class LineIterator
{
public: 
    std::pair<int, int> ptr;
    Direction dir;
    using PointerType = std::pair<int, int>;
public:
    LineIterator(std::pair<int, int>, Direction);

    LineIterator& operator++();
    LineIterator& operator++(int);

    LineIterator& operator--();
    LineIterator& operator--(int);

    bool operator==(const LineIterator& other) const;
    bool operator!=(const LineIterator& other) const;

    PointerType operator*();
};

class Line
{
    std::pair<int, int> start_p;
    std::pair<int, int> end_p;
    Direction dir;

public:
    Line(std::pair<int, int>, std::pair<int, int>);
    bool walk();
    bool walk_diag();
    bool is_diag();

    // iterator
    LineIterator begin();
    LineIterator end();
};
