#include <string>
using std::string;

struct Person {
	
	string get_name() const { return name; }
	
	string get_adress() const { return adress; }
	
	string name = "Generic Name";
	string adress = "123, Fake st";
};

int main() {};
