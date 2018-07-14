#include <iostream>
#include <vector>
#include <list>

int main() {
	std::vector<int> v = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	std::list<int>   l = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	auto vi = v.begin();
	std::cout << "Odd:  ";
	while (vi != v.end())
		if (*vi % 2 == 0)
			vi = v.erase(vi);
		else {
			std::cout << *vi << ' ';
			++vi;
		}
	auto li = l.begin();
	std::cout << "\nEven: ";
	while (li != l.end())
		if (*li % 2 != 0)
			li = l.erase(li);
		else {
			std::cout << *li << ' ';
			++li;
		}
	std::cout << std::endl;
}