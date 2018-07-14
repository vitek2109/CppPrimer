#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::ifstream in_s("infile");
    std::istream_iterator<std::string> in(in_s), eof;
    std::ostream_iterator<std::string> out(std::cout, " ");
    std::vector<std::string> v(in, eof);
    for (auto s : v)
        *out++ = s;
}