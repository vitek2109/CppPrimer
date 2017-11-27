#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string s1, s2;
    cout << "Enter two lines: " << endl;
    getline (cin, s1);
    getline (cin, s2);
    if (s1.size() == s2.size())
        cout << "The strings are equal length." << endl;
    else if (s1.size() < s2.size())
        cout << "\"" + s2 + "\" is longer than " + "\"" + s1 + "\"." << endl;
    else
        cout << "\"" + s1 + "\" is longer than " + "\"" + s2 + "\"." << endl;
} 