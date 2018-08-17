#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

// makes string lowecase
void lower(std::string &s) { 
    for (auto c : s)
        if (c > 'A' && c < 'Z')
            c += 32;
}

int main() {
    std::ifstream in("text.txt");
    std::map<std::string, std::set<int>> line_map;
    std::vector<std::string> line_vector;
// fill the map
    int line_num = 0;
    std::string line;
    while (getline(in, line)) {
        ++line_num;
        line_vector.push_back(line);
        std::istringstream line_stream(line);
        std::string word;
        while (line_stream >> word)
            line_map[word].insert(line_num);
    }
// process user input
    do {
        std::string query;
        std::cout << "Enter a query or 'q' to quit:" << std::endl;
        if (!(std::cin >> query) || query == "q") break;
        auto line_set = line_map[query];
        std::cout << query << " was found in " << line_set.size() << " lines" << std::endl;
        for (auto i : line_set) {
            std::cout << "(line " << i << ") " << line_vector[i-1] << std::endl;
        }
    } while (true);
}