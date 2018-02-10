#include <iostream>
#include <string>
using std::cout; using std::endl; using std::cin; using std::string;

int main()
{
    string prevWord, word, frequentWord;
    cin >> prevWord;
    frequentWord = prevWord;
    int repeates = 1, maxRepeates = 1;
    while (cin >> word)
    {
        if (word == prevWord)
        {
            ++repeates;
            if (repeates > maxRepeates)
            {
                maxRepeates = repeates;
                frequentWord = word;
            }
        }
        else
        {
            prevWord = word;
            repeates = 1;
        }
    }
    if (maxRepeates == 1)
        cout << "No words repeating" << endl;
    else
        cout << "The most frequent word is \"" << frequentWord << "\"\nIt has been repeated " << maxRepeates << " times." << endl;
}