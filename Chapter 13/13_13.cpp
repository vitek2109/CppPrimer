#include <iostream>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(X &x) { std::cout << "X(X &x)" << std::endl; }
    X &operator= (X &x) { std::cout << "X &operator= (X &x)" << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void foo (X x) {};

void bar (X &x) {};

int main() {
    X x1;
    X x2 = x1;
    X x3;
    x3 = x2;
    X x4, x5;
    x5 = x4 = x3;
    foo(x1);
    bar(x1);
    X x7;
    X *px1 = new X();
    delete px1;
    X x6;
    foo(x1);
    foo(x1);
}