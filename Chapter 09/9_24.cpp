#include <vector>
#include <iostream>

int main() {
	std::vector<int> v = {};
	std::cout << v[0] << std::endl;
	v.front() = 21;
	std::cout << *(v.begin()) + v.at(0) << std::endl;
}