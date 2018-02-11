#include <iostream>
#include <iterator>
using std::cout; using std::endl; using std::begin; using std::end;

void print (const int &n)
{
    cout << n << endl;
}

// using marker
void print (const char *s)
{
    if (s)
        while (*s)
            cout << *s++;
}

// using iterators
void print (const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << ' ';
    cout << endl;
}

// old-style, using  size
void print (const int *arr, const size_t &size)
{
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int i = 0;
    int j[2] = {0, 1};
    
    print (i);
    print (begin(j), end(j));
    print (j, end(j) - begin(j));
}