#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> grades;
    vector<int> scores(11, 0);
    int grade;
    while (cin >> grade)
        grades.push_back(grade);
    for (auto grade = grades.begin(); grade != grades.end(); grade++)
    {
        if (*grade <= 100)
            ++scores[(*grade)/10];
    }
    for (auto e : scores)
        cout << e << " ";
    cout << endl;
}