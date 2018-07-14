#include <iostream>
#include <string>
using std::istream; using std::ostream; using std::endl; using std::string;

struct Sales_data {
	
	string isbn() const { return bookNo; }
	
	double avg_price() const { return (units_sold == 0) ? 0 : revenue / units_sold; }
	
	Sales_data &combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream &read (istream &in, Sales_data &item) {
	double price = 0;
	in >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return in;
}

ostream &print (ostream &out, const Sales_data &item) {
	out <<  "---------------------------------------------" << endl <<
			"Book: " << item.isbn() << endl <<
			"Units sold: " << item.units_sold << endl <<
			"For an average price of: " << item.avg_price() << endl <<
			"Totaling: " << item.revenue << endl <<
			"---------------------------------------------" << endl;
}

int main() {}
