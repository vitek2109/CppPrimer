#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
    int grade = 89;
    vector<string> grades = { "F", "D", "C", "B", "A", "A++" };
    string lettergrade;
    if (grade < 60)
        lettergrade = grades[0];
    else
        lettergrade = grades[(grade-50)/10];
    if (grade != 100)
        if (grade < 3)
            lettergrade += '-';
        else if (grade > 7)
            lettergrade += '+';
    cout << lettergrade << endl;
}
