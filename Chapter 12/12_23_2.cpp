#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello ", s2 = "World!";
    char *a = new char[s1.size() + s2.size() + 1];
    for (int i = 0; i < s1.size() + s2.size() + 1; ++i) {
        if (i < s1.size())
            a[i] = s1[i];
        else
            a[i] = s2[i-s1.size()];
    }
    for (int i = 0; i < 13; ++i)
        std::cout << a[i];
    std::cout << std::endl;
    delete [] a;
}