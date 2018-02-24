#include <iostream>
#include <string>
using std::cout; using std::cerr; using std::endl; using std::cin; using std::string;

struct Sales_data {
	
	string isbn() const { return bookNo; }
	
	Sales_data& combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				cout << "-----------------" << endl <<
						"Book: " << total.isbn() << endl <<
						"Units sold: " << total.units_sold << endl <<
						"Book revenue: " << total.revenue << endl << 
						"-----------------" << endl;
				total = trans;
			}
		}
		cout << "-----------------" << endl <<
				"Book: " << total.isbn() << endl <<
				"Units sold: " << total.units_sold << endl <<
				"Book revenue: " << total.revenue << endl << 
				"-----------------" << endl;
	}
	else {
		cerr << "No data!" << endl;
		return -1;
	}
}
