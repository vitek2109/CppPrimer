#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    friend std::ostream& print(std::ostream &os, const HasPtr &p);
public:
    HasPtr(const std::string &s = std::string()) :
            ps(new std::string(s)), i(0) { std::cout << "Basic Constructor" << std::endl; }
    HasPtr(const HasPtr &hp)
        : ps(new std::string(*hp.ps)), i(hp.i) { std::cout << "Copy Constructor" << std::endl; }
    HasPtr(HasPtr &&hp)
        : ps(hp.ps), i(hp.i) { std::cout << "Move Constructor" << std::endl; hp.ps = nullptr; }
    // HasPtr& operator=(HasPtr rhs)
    // {
    //     std::cout << "Swap-Assignment Operator" << std::endl;
    //     swap(*this, rhs);
    //     return *this;
    // }
    HasPtr& operator=(const HasPtr &rhs)
    {
        std::cout << "Copy-Assignment Operator" << std::endl;
        auto temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    HasPtr& operator=(HasPtr &&rhs) noexcept
    {
        std::cout << "Move-Assignment Operator" << std::endl;
        if (this != &rhs) {
            delete ps;
            ps = rhs.ps;
            i = std::move(rhs.i);
            rhs.ps = nullptr;
        }
        return *this;
    }
    ~HasPtr()
    {
        std::cout << "Destructor" << std::endl;
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    HasPtr p0("Hello, World!");
    HasPtr p1(p0);
    HasPtr p2(std::move(p1));
    HasPtr p3; p3 = p2;
    HasPtr p4; p4 = std::move(p3);
}