#include <iostream>

int main()
{
    // (a)
    // std::cin >> int input_value; // expected primary-expression before 'int'
    // (b)
    // int i = { 3.14 }; // narrowing conversion
    // (c)
    // double salary = wage = 9999.99; // 'wage' was not declared
    // (d)
    int i = 3.14; // ok, but some value is lost in conversion
}
