#include <iostream>

int main() {
    size_t s1 = 7, s2 = 7, s3 = s1 + s2 - 1;
    char ca1[s1] = "Hello ", ca2[s2] = "World!";
    char *a = new char[s3];
    for (int i = 0; i < s3; ++i) {
        if (i < s1)
            a[i] = ca1[i];
        else
            a[i] = ca2[i-s1];
    }
    for (int i = 0; i < 13; ++i)
        std::cout << a[i];
    std::cout << std::endl;
    delete [] a;
}