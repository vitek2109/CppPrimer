#include <iostream>
using std::cout; using std::endl;

void print (const char *s)
{
    if (s)
        while (*s)
            cout << *s++;
    cout << endl;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i <= argc; ++i)
        print(argv[i]);
}