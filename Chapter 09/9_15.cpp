#include <vector>

bool equal(std::vector<int> v0, std::vector<int> v1) {
	if (v0.size() != v1.size())
		return false;
	auto b0 = v0.begin();
	auto b1 = v1.begin();
	while (b0 != v0.end())
		if (*(b0++) != *(b1++))
			return false;
	return true;
}

int main() {}