#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str = "Hello World!";
    for (auto &c : str)
        c = 'X';
    cout << str << endl;
}