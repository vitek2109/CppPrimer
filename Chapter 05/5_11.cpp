#include <iostream>
using std::cout; using std::endl; using std::cin;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt= 0, oCnt = 0, uCnt = 0, spCnt = 0, tbCnt = 0, nlCnt = 0;
    char c;
    while (cin >> c)
        switch (c) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spCnt;
                break;
            case '\t':
                ++tbCnt;
                break;
            case '\n':
                ++nlCnt;
                break;
            default:
                break;
        }
    cout << "a " << aCnt << '\n'
         << "e " << eCnt << '\n'
         << "i " << iCnt << '\n'
         << "o " << oCnt << '\n'
         << "u " << uCnt << '\n'
         << "sp " << spCnt << '\n'
         << "tb " << tbCnt << '\n'
         << "nl " << nlCnt << endl;
}
