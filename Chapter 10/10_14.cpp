#include <iostream>

int main(){
    auto sum = [a] (const int &a, const int &b) { return a + b; };
    std::cout << sum(1, 2) << std::endl;
}