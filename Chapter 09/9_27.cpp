#include <iostream>
#include <forward_list>

int main() {
	std::forward_list<int> fl;
	int n;
	while (std::cin >> n)
		fl.push_front(n);
	auto prev = fl.before_begin(), curr = fl.begin();
	while (curr != fl.end()) {
		if (*curr % 2 != 0) {
			curr = fl.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}
	for (auto i = fl.begin(); i != fl.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
}