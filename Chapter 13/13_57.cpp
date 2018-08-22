#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
public:
    Foo(std::vector<int> v = std::vector<int>()) : data(v) { }
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    std::cout << "Sorted for r-value" << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}
Foo Foo::sorted() const &
{
    std::cout << "Sorted for l-value" << std::endl;
    return Foo(*this).sorted();    
}

int main()
{
    Foo f0({ 5, 4, 3, 2, 1 }), f1 = f0.sorted();
}
