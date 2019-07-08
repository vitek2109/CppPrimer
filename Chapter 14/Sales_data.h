#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>

class Sales_data {
	friend std::istream &read (std::istream &, Sales_data &);
	friend std::istream &operator>> (std::istream &, Sales_data &);
	friend std::ostream &print (std::ostream &, const Sales_data &);
	friend std::ostream &operator<< (std::ostream &, const Sales_data &);
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, const unsigned &n, const double &p): bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(std::istream &);
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs);
    Sales_data &operator+=(const Sales_data &);
private:
	inline double avg_price() const { return (units_sold == 0) ? 0 : revenue / units_sold; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream &read (std::istream &, Sales_data &);
std::istream &operator>> (std::istream &, Sales_data &);
std::ostream &print (std::ostream &, const Sales_data &);
std::ostream &operator<< (std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);

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

std::istream &operator>> (std::istream &is, Sales_data &item) {
  double price;
  in >> item.bookNo >> item.units_sold >> price;
  if (is)
    item.revenue = item.units_sold * price;
  else
    item = Sales_data();

  return is;
}

std::ostream &print (std::ostream &out, const Sales_data &item) {
	out << item.isbn() << " " << item.units_sold <<
        " " << item.revenue << " " << item.avg_price();
			return out;
}

std::ostream &operator<< (std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold <<
        " " << item.revenue << " " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data Sales_data::&operator+=(const Sales_data & rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

#endif
