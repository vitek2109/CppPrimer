#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> make_vector() {
    return std::make_shared<std::vector<int>>();
}

void read (std::shared_ptr<std::vector<int>> v) {
    int n;
    while (std::cin >> n)
        v->push_back(n);
}

void print (std::shared_ptr<std::vector<int>> v) {
    for (auto e : *v)
        std::cout << e << " ";
    std::cout << std::endl;
}

int main() {
    auto v = make_vector();
    read(v);
    print(v);
}