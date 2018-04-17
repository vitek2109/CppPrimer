#include <vector>

std::vector<int>::iterator in(std::vector<int>::iterator b, std::vector<int>::iterator e, int n) {
	while (b != e)
		if (*(b++) == n)
			return b;
	return std::vector<int>::iterator(0);
}

int main() {}