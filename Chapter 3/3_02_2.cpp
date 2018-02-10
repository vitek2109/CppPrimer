#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string word;
	cout << "Enter the string:" << endl;
	while (cin >> word)
		cout << word << endl;
}
