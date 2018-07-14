#include <iostream>
#include <string>

void task (std::string &s, std::string oldVal, std::string newVal) {
    for (int i = 0; i < s.size(); ++i) {
        if (s.substr(i, oldVal.size()) == oldVal)
            s.replace(i, oldVal.size(), newVal);
    }
}

int main() {
    std::string s("thothothru");
    task (s, "tho", "though");
    task (s, "thru", "through");
    std::cout << s << std::endl;
}
