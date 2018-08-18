#include <iostream>
#include <string>

class Employee {
public:
    Employee() : name("Blank"), id(n++) { }
    Employee(const std::string &s) : name(s), id(n++) { }
    Employee(const Employee &e) { name = e.name; }
    Employee& operator= (const Employee &rhs) { name = rhs.name; }
    void hello() { std::cout << "Hello, my name is " << name << " and my id is " << id << "." << std::endl; }
private:
    std::string name;
    size_t id;
    static size_t n;
};
size_t Employee::n = 0;

int main() {
    Employee e0, e1("Steve");
    e0.hello();
    e1.hello();
    e1 = e0;
    e1.hello();
}