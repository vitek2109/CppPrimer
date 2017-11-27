#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
	string line;
	cout << "Enter the line:" << endl;
	while (getline(cin, line))
		cout << line << endl;
}
