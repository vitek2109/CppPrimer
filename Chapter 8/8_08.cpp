#include <iostream>
#include <fstream>
#include "Sales_data.h"

int main(int argc, char *argv[]) {
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2], std::ofstream::app);
	Sales_data total;
	if(read(in, total)) {
		Sales_data trans;
		while(read(in, trans)) {
			if (trans.isbn() == total.isbn())
				total.combine(trans);
			else {
				print(out, total);
				total = trans;
			}
		}
		print(out, total);
	}
	else {
		std::cerr << "No Data!" << std::endl;
	}
}
