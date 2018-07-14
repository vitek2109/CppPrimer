#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
    vector<string> text;
    string word;
    while(cin >> word)
        text.push_back(word);
    int i = 0;
    for (auto w : text)
    {
        for (auto &c : w)
            c = toupper(c);
        if (i++ % 8 == 0)
            cout << endl;
        cout << w << " ";    
    }
    cout << endl;
}