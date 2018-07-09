#include <iostream>

int main() {
    int n = 10;
    auto f = [n] () mutable -> bool { 
        if (n-- == 0) 
            return true; 
        else {  
            return false; 
        } 
    };
    while (!f()) 
        std::cout << "false" << std::endl;
    std::cout << "true" << std::endl;
}