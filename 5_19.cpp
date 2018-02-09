#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string s1, s2, rsp;
    do {
        cin >> s1 >> s2;
        if (s1 == s2)
            cout << "Strings are equal.\n" << endl;
        else if (s1.size() > s2.size())
            cout << "First string is bigger.\n" << endl;
        else
            cout << "Second string is bigger.\n" << endl;
        cout << "Do you have more strings?" << endl;
        cin >> rsp;
    } while (rsp[0] != 'n' && !rsp.empty());
}