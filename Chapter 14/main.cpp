// These are tests for all the classes

#include "StrVec.h"
#include "Sales_data.h"
#include "String.h"

int main() {
    std::cout << "StrVec Test Start" << std::endl;
	StrVec v;
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push_back("Hello,");
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.push_back(" World!");
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b;
    std::cout << std::endl;
    StrVec v1(v), v2;
    v2 = v;
    for (auto b = v1.begin(); b != v1.end(); ++b)
        std::cout << *b;
    std::cout << std::endl;
    for (auto b = v2.begin(); b != v2.end(); ++b)
        std::cout << *b;
    std::cout << std::endl;
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    v.reserve(10);
    v.resize(50, "#");
    v.resize(10);
    std::cout << v.size() << ' ' << v.capacity() << std::endl;
    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b;
    std::cout << std::endl;
    StrVec v3({"Hello,", " World!"});
    for (auto b = v3.begin(); b != v3.end(); ++b)
        std::cout << *b;
    std::cout << std::endl;
    std::cout << "StrVec Test End" << std::endl;
}
