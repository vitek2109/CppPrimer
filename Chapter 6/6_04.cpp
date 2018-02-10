#include <iostream>
using std::cout; using std::endl; using std::cin;

// n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
long long fact (long long n)
{
    int r = 1;
    while (n > 1)
        r *= n--;
    return r;
}

void interaction()
{
    cout << "Hello there\nI am a factorial counter\nInput any number and I will output it's factorial =D\n";
    long long n;
    cin >> n;
    cout << fact(n) << endl;
}

int main()
{
    interaction();
}