#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>

class Sales_data {
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
public:
	Sales_data(std::string s = "") : bookNO(s), number_sold(0), revenue(0.0) {}
	Sales_data(std::string s, unsigned n, double p) : bookNO(s), number_sold(n), revenue(p*n) {}
	Sales_data(const Sales_data &s) : bookNO(s.bookNO), number_sold(s.number_sold), revenue(revenue) {}
	Sales_data& operator=(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);
	std::string isbn() { return bookNO; }
	double avg_price() const { return revenue / number_sold; }
private:
	std::string bookNO;
	unsigned number_sold;
	double revenue;
};

Sales_data operator+(const Sales_data&, const Sales_data&);
std::istream& operator>>(std::istream&, const Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);

Sales_data& Sales_data::operator=(const Sales_data &rhs) {
	bookNO = rhs.bookNO;
	number_sold = rhs.number_sold;
	revenue = rhs.revenue;
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
	number_sold += rhs.number_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

std::istream& operator>>(std::istream &is, Sales_data &s) {
	is >> s.bookNO >> s.number_sold >> s.revenue;
	if (is)
		s = Sales_data();
	return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &s) {
	os << s.bookNO << ' ' << s.number_sold << ' ' << s.avg_price() << ' ' << s.revenue;
	return os;
}

#endif
