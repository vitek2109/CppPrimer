#include <iostream>
#include <string>

void task (std::string &s, std::string pre, std::string suf) {
    s.insert(0, pre + " ");
    s.insert(s.size(), " " + suf);
}

int main() {
    std::string s("Smith"), pre("Mr."), suf("Jr.");
    task (s, pre, suf);
    std::cout << s << std::endl;
}