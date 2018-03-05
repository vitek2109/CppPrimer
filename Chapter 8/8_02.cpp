#include <iostream>
#include <string>
using std::istream; using std::cin; using std::cout; using std::endl; using std::string;

std::istream &process(std::istream& in) {
	while (!in.eof()) {
		string input;
		getline (in, input);
		cout << input << endl;
	}
	in.clear();
	return in;
}

int main() {
	process(cin);
}
