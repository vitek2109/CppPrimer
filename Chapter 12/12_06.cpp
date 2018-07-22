#include <iostream>
#include <vector>

std::vector<int>* make_vector() {
    return new std::vector<int>;
}

void read (std::vector<int> *v) {
    int n;
    while (std::cin >> n)
        v->push_back(n);
}

void print (std::vector<int> *v) {
    for (auto e : *v)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main() {
    auto v = make_vector();
    read(v);
    print(v);
    delete v;
}