#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    bool operator< (const HasPtr &rhs) { return *(this->ps) < *rhs.ps; }
    ~HasPtr() {
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "Begin swap()" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "End swap()" << std::endl;
}

int main() {
    std::vector<HasPtr> v;
    v.push_back(HasPtr("42"));
    v.push_back(HasPtr("Hello"));
    v.push_back(HasPtr("42"));
    v.push_back(HasPtr("World"));
    v.push_back(HasPtr("42"));
    v.push_back(HasPtr("How are you?"));
    v.push_back(HasPtr("42"));
    std::sort(v.begin(), v.end());
}