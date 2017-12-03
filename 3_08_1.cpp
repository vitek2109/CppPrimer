#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str = "Hello World!";
    decltype(str.size()) i = 0;
    while (i < str.size())
        str[i++] = 'X';
    cout << str << endl;
}