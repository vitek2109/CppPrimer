#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(int argc, char *argv[]) {
	std::ifstream in("infile");
	std::vector<std::string> v;
	while (in) {
		std::string s;
		getline(in, s);
		v.push_back(s);
	}
	for (auto b = v.begin(); b != v.end(); ++b) {
		std::istringstream instr(*b);
		std::string s;
		while (instr >> s)
			std::cout << s << std::endl;
	}
}
