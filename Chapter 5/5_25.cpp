#include <iostream>
#include <stdexcept>
using std::cout; using std::endl; using std::cin; using std::runtime_error;

int main()
{
    int n, m;
    try {
        cin >> n >> m;
        if (m == 0)
            throw runtime_error("Dude\nYou can't divide by zero\nInput again you little s#!t\n");
    } catch (runtime_error err) {
        cout << err.what();
        cin >> n >> m;
    }
    cout << n/m << endl;
}