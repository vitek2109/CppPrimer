#include <iostream>

struct numbered {
    numbered() { mysn = n++; }
    int mysn;
    static int n;
};

int numbered::n = 0;

void f (numbered s) { std::cout << s.mysn << std::endl; }

int main() {
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}