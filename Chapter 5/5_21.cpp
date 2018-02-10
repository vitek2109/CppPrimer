#include <iostream>
#include <string>
using std::cout; using std::endl; using std::cin; using std::string;

int main()
{
    string s1, s2;
    cin >> s1;
    while (cin >> s2)
        if (s2[0] > 90 || s2[0] < 65)
            continue;
        else if (s1 == s2)
        {
            cout << s1 << endl;
            return 0;
        }
        else
            s1 = s2;
    cout << "No repeating words" << endl;
}