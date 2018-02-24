#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>

class Person {
	friend std::istream &read(std::istream &, Person &);
	friend std::ostream &print(std::ostream &, Person &);
public:
	Person() = default;
	Person(const std::string &n): name(n) {}
	Person(const std::string &n, const std::string &a): name(n), adress(a) {}
	
	std::string get_name() const { return name; }
	std::string get_adress() const { return adress; }
private:	
	std::string name = "Generic Name";
	std::string adress = "123, Fake st";
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, Person &);

std::istream &read(std::istream &in = std::cin, Person &p) {
	in >> p.name >> p.adress;
	return in;
}

std::ostream &print(std::ostream &out = std::cout, Person &p) {
	out <<  "Hi my name is " << p.get_name() << std::endl <<
			"I live on " << p.get_adress() << std::endl;
}
#endif