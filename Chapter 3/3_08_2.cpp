#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str = "Hello World!";
    for (decltype(str.size()) i = 0; i < str.size(); ++i)
        str[i] = 'X';
    cout << str << endl;
}