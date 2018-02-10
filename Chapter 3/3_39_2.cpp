#include <iostream>
#include <iterator>
using std::cout; using std::endl; using std::begin; using std::end;
int main()
{
    const char s1[] = "Hello World!";
    const char s2[] = "Hello Again!";
    bool equal = true;
    auto s1b = begin(s1), s1e = end(s1);
    auto s2b = begin(s2), s2e = end(s2);
    while (equal && s1b < s1e && s2b < s2e)
    {
        if (*s1b != *s2b)
            equal = false;
        ++s1b;
        ++s2b;
    }
    cout << equal << endl;
}