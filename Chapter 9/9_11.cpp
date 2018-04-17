#include <vector>

int main() {
	std::vector<int> v0; // {}
	std::vector<int> v1{0, 1, 2, 3, 4};
	std::vector<int> v2(v1); // {0, 1, 2, 3, 4}
	std::vector<int> v3(v1.begin(), v1.end()); // {0, 1, 2, 3, 4}
	std::vector<int> v4(5); // {0, 0, 0, 0, 0}
	std::vector<int> v5(5, 1); // {1, 1, 1, 1, 1}
}