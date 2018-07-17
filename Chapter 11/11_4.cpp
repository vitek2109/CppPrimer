#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

std::string titlecase (std::string s) {
    if (s[0] >= 97 && s[0] <= 122)
        s[0] -= 32;
    return s;
}

std::string lowercase (std::string s) {
    for (auto &e : s)
        if (e > 65 && e < 90)
            e += 32;
    return s;
}

void remove_punct (std::string &s) {
    std::set<char> punct{',', '.', '"', '(', ')', '-', ';', '!', '?'};
    for (auto b = s.begin(); b != s.end(); ++b) {
        if (punct.find(*b) != punct.end()) {
            b = s.erase(b);
            --b;
        }
    }
}

int main() {
    std::ifstream in("text.txt");
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude{"", "a", "the", "but"};
    std::string word;
    while (in >> word) {
        remove_punct(word);
        if (exclude.find(lowercase(word)) == exclude.end())
            ++word_count[lowercase(word)];
    }
    for (auto e : word_count)
        std::cout << titlecase(e.first) << "\tappeares " << e.second << (e.second > 1 ? " times." : " time.") << std::endl;
    in.close();
}
