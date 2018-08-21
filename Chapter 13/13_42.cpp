#include "StrVec.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <vector>

class TextQuery {
public:
    TextQuery(std::ifstream& in);
    void print (std::ostream& out, std::string s);
private:
    StrVec line_vector;
    std::map<std::string, std::set<size_t>> line_map;
};

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);
void lower(std::string &s);

TextQuery::TextQuery(std::ifstream& in) {
    int line_num = 0;
    std::string line;
    while (getline(in, line)) {
        line_vector.push_back(line);
        ++line_num;
        std::istringstream line_stream(line);
        std::string word;
        while (line_stream >> word) {
            lower(word);
            line_map[word].insert(line_num);
        }
    }
}

void TextQuery::print (std::ostream& out, std::string s) {
    lower(s);
    auto &line_set = line_map[s];
    std::cout << s << " was found in " << line_set.size() << make_plural(line_set.size(), " line", "s") << std::endl;
    for (int i : line_set) {
        std::cout << "\t(line " << i << ") " << line_vector.at(i-1) << std::endl;
    }
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending) {
    return ctr > 1 ? word + ending : word;
}

void lower(std::string &s) {
    for (auto c : s)
        if (c > 'A' && c < 'Z')
            c += 32;
}

void runQueries(std::ifstream &in) {
    TextQuery tq(in);
    while (true) {
        std::string query;
        std::cout << "Enter a query or 'q' to quit:" << std::endl;
        if (!(std::cin >> query) || query == "q") break;
        tq.print (std::cout, query);
    }
}

int main() {
    std::ifstream in("text.txt");
    runQueries(in);
}
