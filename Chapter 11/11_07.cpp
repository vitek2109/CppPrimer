#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

void new_children (std::map<std::string, std::vector<std::string>> &families, std::string family, const std::vector<std::string> children) {
    std::copy (children.begin(), children.end(), std::back_inserter(families[family]));
}

int main() {
    std::map<std::string, std::vector<std::string>> families = { {"Smith", {"Spencer", "Sam"} } };
    new_children (families, "Jonhson", std::vector<std::string>{"Jonh", "Jack"});
    for (auto e : families) {
        std::cout << e.first << ": ";
        for (auto s : e.second) {
            std::cout << s << ' ';
        }
        std::cout << std::endl;
    }
}
