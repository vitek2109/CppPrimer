#include <iostream>
#include <map>
#include <string>

void erase (std::multimap<std::string, std::string> &map, const std::string &val) {
    if (map.find(val) != map.end())
        map.erase(map.find(val));
}

int main() {
    std::multimap<std::string, std::string> authors;
    authors.insert(authors.end(), std::make_pair("1", "1"));
    authors.insert(authors.end(), std::make_pair("1", "2"));
    authors.insert(authors.end(), std::make_pair("2", "1"));
    authors.insert(authors.end(), std::make_pair("2", "2"));
    for (auto e : authors)
        std::cout << e.first << " : " << e.second << std::endl;
    std::cout << std::endl;
    erase(authors, "2");
    for (auto e : authors)
        std::cout << e.first << " : " << e.second << std::endl;
    std::cout << std::endl;
    erase(authors, "3");
    for (auto e : authors)
        std::cout << e.first << " : " << e.second << std::endl;
}