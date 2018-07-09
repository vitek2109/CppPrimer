#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

void elimDupl(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto erase_begin = std::unique(words.begin(), words.end());
    words.erase(erase_begin, words.end());
    std::stable_sort(words.begin(), words.end(), isShorter);
}

void biggies(std::vector<std::string> &words, std::string::size_type sz) {
    elimDupl(words);
    auto print_end = std::partition(words.begin(), words.end(), [sz] (const std::string &s) { return s.size() >= sz; });
    std::for_each(words.begin(), print_end, 
        [] (const std::string &s)
            { std::cout << s << ' '; });
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
}