#include <iostream>
#include <deque>
#include <string>

int main() {
	std::deque<std::string> sd;
	std::string word;
	while (std::cin >> word)
		sd.push_back(word);
	for (std::deque<std::string>::iterator i = sd.begin(); i != sd.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
}