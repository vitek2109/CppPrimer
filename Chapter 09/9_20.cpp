#include <deque>
#include <list>
#include <iostream>

int main() {
	std::list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::deque<int> even, odd;
	for (auto i = lst.begin(); i != lst.end(); ++i) {
		if ((*i) % 2 == 0)
			even.push_back(*i);
		else
			odd.push_back(*i);
	}
	std::cout << "Even: ";
	for (auto i = even.begin(); i != even.end(); ++i)
		std::cout << *i << ", ";
	std::cout << "\nOdd: ";
	for (auto i = odd.begin(); i != odd.end(); ++i)
		std::cout << *i << ", ";
}