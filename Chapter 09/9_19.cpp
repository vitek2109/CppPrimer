#include <iostream>
#include <list>
#include <string>

int main() {
	std::list<std::string> sd;
	std::string word;
	while (std::cin >> word)
		sd.push_back(word);
	for (std::list<std::string>::iterator i = sd.begin(); i != sd.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
}