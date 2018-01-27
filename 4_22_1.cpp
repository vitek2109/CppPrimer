#include <iostream>
using std::cout; using std::endl;

int main()
{
    int grade = 78;
    cout << ( (grade > 90) ? "High pass"
                           : (grade > 75) ? "Pass"
                                          : (grade < 60) ? "Fail" : "Low pass" ) << endl;
}
