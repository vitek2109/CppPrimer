#include <iostream>
#include <string>

void task (std::string &s, std::string pre, std::string suf) {
    s.insert(s.begin(), 1, ' ');
    s.insert(s.begin(), pre.begin(), pre.end());
    s.append(" " + suf);
}

int main() {
    std::string s("Smith"), pre("Mr."), suf("Jr.");
    task (s, pre, suf);
    std::cout << s << std::endl;
}