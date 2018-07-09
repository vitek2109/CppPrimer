#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool check_size (const std::string &s, std::string::size_type sz) {
    return s.size() >= sz;
}

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
    auto print_end = std::stable_partition(words.begin(), words.end(), std::bind(check_size, _1, sz));
    std::for_each(words.begin(), print_end, 
        [] (const std::string &s)
            { std::cout << s << ' '; });
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
}