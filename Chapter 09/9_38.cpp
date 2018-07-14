#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    std::cout << '\n' << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

    for (std::vector<int>::size_type i = 0; i < 25; ++i)
        v.push_back(i);

    std::cout << '\n' << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

    while (v.size() != v.capacity())
        v.push_back(0);

    std::cout << '\n' << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

    v.push_back(42);

    std::cout << '\n' << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;

    v.shrink_to_fit();

    std::cout << '\n' << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
}