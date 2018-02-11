#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string;

int main (int argc, char *argv[])
{
    string result = "";
    for (int i = 1; i < argc; ++i)
        result += argv[i];
    cout << result << endl;
}