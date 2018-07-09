#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

int main() {
    std::vector<Sales_data> v{Sales_data("15"), Sales_data("1"), Sales_data("3"), Sales_data("2")};
    std::sort(v.begin(), v.end(), 
        [] (const Sales_data &s1, const Sales_data &s2) 
            { return s1.isbn() < s2.isbn(); });
    for (const auto &s : v)
        std::cout << s.isbn() << ' ';
    std::cout << std::endl;
}