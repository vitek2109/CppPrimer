#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data data1, data2;
    unsigned thisDoesNotMatter;
    double onlyISBNMatters;
    cin >> data1.bookNo >> thisDoesNotMatter >> onlyISBNMatters;
    int cnt = 1;
    while (cin >> data2.bookNo)
    {
        cin >> thisDoesNotMatter >> onlyISBNMatters;
        if (data1.bookNo == data2.bookNo)
            ++cnt;
        else
        {
            cout << data1.bookNo << " occurs " << cnt << " times." << endl;
            data1.bookNo = data2.bookNo;
            cnt = 1;
        }
    }
    cout << data1.bookNo << " occurs " << cnt << " times." << endl;
}
