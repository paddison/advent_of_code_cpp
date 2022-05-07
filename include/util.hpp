#include <string>
#include <vector>

using namespace std;

vector<int> parse_file(string);
vector<string> parse_lines(string);
vector<string> split_string(string, const string);

vector<int> map_to_int(vector<string> input);

void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);