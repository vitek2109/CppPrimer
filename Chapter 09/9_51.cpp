#include <iostream>
#include <string>

class Date {
    private:
        int year, month, day;
    public:
        Date(std::string date) { // It'll only accept ISO format (yyyy-mm-dd)
            year  = std::stoi(date.substr(0, 4));
            month = std::stoi(date.substr(5, 2));
            day   = std::stoi(date.substr(8, 2));
        }
        void print() {
            std::cout << "It's day " << day << " of month " << month << " of year " << year << std::endl;
        }
};

int main() {
    Date d("1970-01-01");
    d.print();
}
