#include <vector>
#include <optional>

using namespace std;

namespace day_4
{
    struct Point
    {
        int row;
        int col;

        Point(int, int);
    };

    class Board 
    {
        const static int mask = 0x40000000;
        public:
        vector<int> values;

        public:
        Board(vector<int>);
        inline int get(int, int);
        void mark(int, int);
        optional<Point> contains_number(int);
        bool is_winner();
        int calculate_score(int);
        inline bool is_marked(int, int);
    };

    int get_solution_1();
    int get_solution_2();
    void test_board();
}