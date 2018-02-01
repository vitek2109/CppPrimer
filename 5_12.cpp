#include <iostream>
#include <string>
using std::cout; using std::endl; using std::cin; using std::string;

int main()
{
    int ffCnt = 0, flCnt = 0, fiCnt= 0;
    string s;
    while (cin >> s)
        switch (s) {
            case "ff":
                ++ffCnt;
                break;
            case "fl":
                ++flCnt;
                break;
            case "fi":
                ++fiCnt;
                break;
            default:
                break;
        }
    cout << "ff " << ffCnt << '\n'
         << "fl " << flCnt << '\n'
         << "fi " << fiCnt << endl;
}
