#include <iostream>
#include <string>

void task (std::string &s, std::string oldVal, std::string newVal) {
    auto b = s.begin();
    while (b != s.end()) {
        std::string slice(b, b + oldVal.size());
        if (slice == oldVal) {
            b = s.erase(b, b + oldVal.size());
            b = s.insert(b, newVal.begin(), newVal.end());
            b += newVal.size();
        }
        else
            ++b;
    }
}

int main() {
    std::string s("thothothru");
    task (s, "tho", "though");
    task (s, "thru", "through");
    std::cout << s << std::endl;
}
