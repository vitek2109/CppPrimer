#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::ifstream in("text.txt");
    std::map<std::string, size_t> word_count;
    std::string word;
    while (in >> word)
        ++word_count[word];
    for (auto e : word_count)
        std::cout << e.first << "\tappeares " << e.second << (e.second > 1 ? " times." : " time.") << std::endl;
    in.close();
}
