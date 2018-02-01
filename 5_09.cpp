#include <iostream>
using std::cout; using std::endl; using std::cin;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt= 0, oCnt = 0, uCnt = 0;
    char c;
    while (cin >> c)
        switch (c) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            default:
                break;
        }
    cout << "a " << aCnt << '\n'
         << "e " << eCnt << '\n'
         << "i " << iCnt << '\n'
         << "o " << oCnt << '\n'
         << "u " << uCnt << endl;
}
