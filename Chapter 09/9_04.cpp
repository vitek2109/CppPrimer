#include <iostream>
#include <vector>

bool in(std::vector<int>::iterator b, std::vector<int>::iterator e, int n) {
	while (b != e)
		if (*(b++) == n)
			return true;
	return false;
}

int main() {
	std::vector<int> v = {0, 1, 2, 3, 4};
	std::cout << in(v.begin(), v.end(), 1) << '\n' << in(v.begin(), v.end(), 5) << std::endl;
}