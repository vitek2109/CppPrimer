#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string;

string make_plural (size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success") << '\n' << make_plural(2, "success") << '\n' << 
			make_plural(1, "failure") << '\n' << make_plural(2, "failure") << endl;
}
 