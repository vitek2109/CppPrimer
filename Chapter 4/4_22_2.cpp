#include <iostream>
using std::cout; using std::endl;

int main()
{
    int grade = 78;
    if (grade > 90)
        cout << "High pass" << endl;
    else if (grade > 75)
        cout << "Pass" << endl;
    else if (grade < 60)
        cout << "Fail" << endl;
    else
        cout << "Low pass" << endl;
}
