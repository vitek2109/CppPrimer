#include <iostream>
#include <cctype>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str;
    cout << "Enter a string with punctuation:" << endl;
    getline(cin, str);
    for (auto c : str)
        if (!ispunct(c))
            cout << c;
    cout << endl;
}