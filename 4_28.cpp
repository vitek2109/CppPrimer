#include <iostream>
using std::cout; using std::endl;

int main()
{
    cout << "Size of char:      " << sizeof(char)      << endl;
    cout << "Size of short:     " << sizeof(short)     << endl;
    cout << "Size of int:       " << sizeof(int)       << endl;
    cout << "Size of long:      " << sizeof(long)      << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of unsigned:  " << sizeof(unsigned)  << endl;
    cout << "Size of int*:      " << sizeof(int*)      << endl;
    cout << "Size of bool:      " << sizeof(bool)      << endl;
    cout << "Size of void:      " << sizeof(void)      << endl;
    cout << "Size of int[5]:    " << sizeof(int[5])    << endl;
}
