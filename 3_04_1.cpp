#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string s1, s2;
    cout << "Enter two lines: " << endl;
    getline (cin, s1);
    getline (cin, s2);
    if (s1 == s2)
        cout << "The strings are equal." << endl;
    else if (s1 < s2)
        cout << "\"" + s2 + "\" is bigger than " + "\"" + s1 + "\"." << endl;
    else
        cout << "\"" + s1 + "\" is bigger than " + "\"" + s2 + "\"." << endl;
} 