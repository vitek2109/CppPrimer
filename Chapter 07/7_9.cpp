#include <iostream>
#include <string>

struct Person {
	
	std::string get_name() const { return name; }
	
	std::string get_adress() const { return adress; }
	
	std::string name = "Generic Name";
	std::string adress = "123, Fake st";
};

std::istream &read(std::istream &in, Person &p) {
	in >> p.name >> p.adress;
	return in;
}

std::ostream &print(std::ostream &out, Person &p) {
	out <<  "Hi my name is " << p.get_name() << std::endl <<
			"I live on " << p.get_adress() << std::endl;
}

int main() {}
