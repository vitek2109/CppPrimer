#include <iostream>

int main()
{
    std::cout << "/*"; // no error
    std::cout << "*/"; // no error
    // std::cout << /* "*/" */; // error
    std::cout << /* "*/" /* "/*" */; // no error
}
