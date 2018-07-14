#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> fi, i, bi;
    std::copy(v.begin(), v.end(), std::front_inserter(fi));
    std::copy(v.begin(), v.end(), std::inserter(i, i.begin()));
    std::copy(v.begin(), v.end(), std::back_inserter(bi));
    std::cout << "Front Inserter: ";
    std::for_each(fi.begin(), fi.end(), [] (int n) { std::cout << n << ' '; } );
    std::cout << std::endl;
    std::cout << "Inserter:       ";
    std::for_each(i.begin(), i.end(),  [] (int n) { std::cout << n << ' '; } );
    std::cout << std::endl;
    std::cout << "Back Inserter:  ";
    std::for_each(bi.begin(), bi.end(), [] (int n) { std::cout << n << ' '; } );
    std::cout << std::endl;
}