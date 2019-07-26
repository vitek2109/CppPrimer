// These are tests for all the classes

#include <iostream>
#include "StrVec.h"
#include "Sales_data.h"
#include "String.h"

int main() {
	std::cout << "------------------------StrVec Test Start------------------------" << std::endl;
		StrVec v;
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	v.push_back("Hello,");
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	v.push_back(" World!");
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	for (auto b = v.begin(); b != v.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	StrVec v1(v), v2;
	v2 = v;
	for (auto b = v1.begin(); b != v1.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	for (auto b = v2.begin(); b != v2.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	v.reserve(10);
	v.resize(50, "#");
	v.resize(10);
	std::cout << v.size() << ' ' << v.capacity() << std::endl;
	for (auto b = v.begin(); b != v.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	StrVec v3({"Hello,", " World!"});
	for (auto b = v3.begin(); b != v3.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	std::cout << "------------------------StrVec Test End--------------------------" << std::endl;


	std::cout << "\n\n\n" << std::endl;
	std::cout << "-----------------------String Test Start-------------------------" << std::endl;
	String s;
	String s1("Hello World");
	String s2(s1);
	String s3, s4;
	s3 = s4 = s1;
	std::cout << s1.size() << ' ' << s1.capacity() << std::endl;
	for (auto b = s1.begin(); b != s1.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	for (auto b = s2.begin(); b != s2.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	for (auto b = s3.begin(); b != s3.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	for (auto b = s4.begin(); b != s4.end(); ++b)
		std::cout << *b;
	std::cout << std::endl;
	std::cout << "------------------------String Test End--------------------------" << std::endl;
	std::cout << "\n\n\n" << std::endl;
	std::cout << "---------------------Sales_data Test Start-----------------------" << std::endl;
	Sales_data sd;
	Sales_data sd1("123123"), sd2("1212", 3, 25);
	Sales_data sd3(sd2);
	Sales_data sd4 = sd3;
	std::cout << "----------------------Sales_data Test End------------------------" << std::endl;
}
