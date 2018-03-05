#include <iostream>
#include <string>
#include <sstream>

std::istream &process(std::istream& in) {
	while (!in.eof()) {
		std::string input;
		getline(in, input);
		std::cout << input << std::endl;
	}
	in.clear();
	return in;
}

int main() {
	std::istringstream in("Hello World!\nGoodbye!");
	process(in);
}
