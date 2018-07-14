#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in("text.txt");
    std::string s, over("tidfhklb"), under("qypgj");
    std::string::size_type max = 0;
    std::string max_s = "";
    while (in >> s) {
        if (s.find_first_of(over) == std::string::npos && s.find_first_of(under) == std::string::npos && s.size() > max) {
            max = s.size();
            max_s = s;
        }
    }
    std::cout << max_s << std::endl;
    in.close();
}