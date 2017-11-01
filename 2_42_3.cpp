#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    unsigned thisDoesNotMatter;
    double onlyISBNMatters;
    std::cin >> data1.bookNo >> thisDoesNotMatter >> onlyISBNMatters;
    int cnt = 1;
    while (std::cin >> data2.bookNo)
    {
        std::cin >> thisDoesNotMatter >> onlyISBNMatters;
        if (data1.bookNo == data2.bookNo)
            ++cnt;
        else
        {
            std::cout << data1.bookNo << " occurs " << cnt << " times." << std::endl;
            data1.bookNo = data2.bookNo;
            cnt = 1;
        }
    }
    std::cout << data1.bookNo << " occurs " << cnt << " times." << std::endl;
}
