#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string sum, s;
    cout << "Enter strings:" << endl;
    while (cin >> s)
        sum += s;
    cout << sum << endl;
}