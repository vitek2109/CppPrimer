#include "MyTextQuery.h"

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
        std::cout << "\t(line " << i << ") " << line_vector[i-1] << std::endl;
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