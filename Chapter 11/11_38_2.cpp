#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <exception>

std::unordered_map<std::string, std::string> make_map (std::ifstream &rules) {
    std::unordered_map<std::string, std::string> res;
    std::string key, value;
    while (rules >> key && std::getline(rules, value)) {
        if (value.size() > 1)
            res[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    }
    return res;
}

const std::string &transform (const std::string &word, const std::unordered_map<std::string, std::string> &rules) {
    auto map_it = rules.find(word);
    if (map_it != rules.cend())
        return map_it->second;
    else
        return word;
}

void word_process (std::ifstream &rules, std::ifstream &text) {
    auto rule_map = make_map(rules);
    std::string line;
    while (std::getline(text, line)) {
        std::istringstream line_stream(line);
        std::string word;
        while (line_stream >> word) {
            std::cout << transform(word, rule_map) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ifstream rules("infile1"), text("infile2");
    word_process(rules, text);
    rules.close();
    text.close();
}