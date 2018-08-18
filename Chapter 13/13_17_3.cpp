#include <iostream>

struct numbered {
    numbered() { mysn = n++; }
    numbered(numbered &a) { mysn = n++; }
    int mysn;
    static int n;
};

int numbered::n = 0;

void f (const numbered &s) { std::cout << s.mysn << std::endl; }

int main() {
    numbered::n = 0;
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}