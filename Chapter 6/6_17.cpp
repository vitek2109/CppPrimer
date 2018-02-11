#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string;

bool has_uppercase (const string &s)
{
    for (auto c : s)
        if (c >= 65 && c <= 90)
            return true;
    return false;
}

void to_lower (string &s)
{
    for (auto &c : s)
        if (c >= 65 && c <= 90)
            c += 32;
}

int main()
{
    string s = "Hello World!";
    cout << s << endl;
    cout << has_uppercase(s) << endl;
    to_lower(s);
    cout << s << endl;
}