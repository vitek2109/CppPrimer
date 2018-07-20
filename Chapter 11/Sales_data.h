#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>

class Sales_data {
	friend std::istream &read (std::istream &, Sales_data &);
	friend std::ostream &print (std::ostream &, const Sales_data &);
	friend Sales_data add(const Sales_data &, const Sales_data &);
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, const unsigned &n, const double &p): bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(std::istream &);
	
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs);
private:
	inline double avg_price() const { return (units_sold == 0) ? 0 : revenue / units_sold; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream &read (std::istream &, Sales_data &);
std::ostream &print (std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);

Sales_data::Sales_data(std::istream &in)
{
	read(in, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read (std::istream &in, Sales_data &item) {
	double price = 0;
	in >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return in;
}

std::ostream &print (std::ostream &out, const Sales_data &item) {
	out <<  "----------------------------------" << std::endl <<
			"Book:\t\t\t\t" << item.isbn() << std::endl <<
			"Units sold:\t\t\t" << item.units_sold << std::endl <<
			"For an average price of:\t" << item.avg_price() << std::endl <<
			"Totaling:\t\t\t" << item.revenue << std::endl <<
			"----------------------------------" << std::endl;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}
#endif