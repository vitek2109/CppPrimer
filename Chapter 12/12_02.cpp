#include <iostream>
#include "StrBlob.h"

int main() {
    StrBlob sb;
    sb.push_back("Hello ");
    sb.push_back("World!");
    std::cout << sb.front() << sb.back() << std::endl;
    sb.pop_back();
    std::cout << sb.front() << sb.back() << std::endl;
    // sb.pop_back(); throws out_of_range
    std::cout << sb.front() << sb.back() << std::endl;
}