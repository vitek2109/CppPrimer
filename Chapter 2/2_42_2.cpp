#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    double price1, price2;
    std::cin >> data1.bookNo >> data1.units_sold >> price1;
    data1.revenue = data1.units_sold * price1;
    while (std::cin >> data2.bookNo)
    {
        std::cin >> data2.units_sold >> price2;
        data2.revenue = data2.units_sold * price2;
        data1.units_sold += data2.units_sold;
        data1.revenue += data2.revenue;
    }
    std::cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue/data1.units_sold << std::endl;
}
