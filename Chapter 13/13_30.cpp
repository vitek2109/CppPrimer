#include <iostream>
#include <string>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    friend std::ostream& print(std::ostream &os, const HasPtr &p);
public:
    HasPtr (const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { }
    HasPtr (const HasPtr &hp) :
            ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator= (const HasPtr &rhs) {
        auto temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << std::endl << "Begin swap()" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "End swap()" << std::endl;
}

std::ostream& print(std::ostream &os, const HasPtr &p) {
    os << *p.ps;
} 

int main() {
    HasPtr p1("World!"), p2("Hello, ");
    print(print(std::cout, p1), p2);
    swap(p1, p2);
    print(print(std::cout, p1), p2);
}
