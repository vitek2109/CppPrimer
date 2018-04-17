#include <vector>
#include <list>

int main() {
	std::list<int> l = {0, 1, 2, 3, 4};
	std::vector<int> v0 = {0, 1, 2, 3, 4};
	std::vector<double> v1(l.begin(), l.end());
	std::vector<double> v2(v0.begin(), v0.end());
}