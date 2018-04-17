#include <list>
#include <vector>
#include <string>

int main() {
	std::list<const char*> l = {"0", "1", "2", "3", "4"};
	std::vector<std::string> v;
	v.assign(l.begin(), l.end());
}