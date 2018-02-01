#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
    int grade = 89;
    vector<string> grades = { "F", "D", "C", "B", "A", "A++" };
    string lettergrade = grade < 60 ? grades[0] : grades[(grade - 50) / 10];
    lettergrade += grade == 100 ? "" :
                   grade % 10 < 3 ? "-" :
                   grade % 10 > 7 ? "+" : "";
    cout << lettergrade << endl;
}
