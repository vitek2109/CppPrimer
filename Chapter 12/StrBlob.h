#ifndef STR_BLOB
#define STR_BLOB
#include <memory>
#include <vector>
#include <string>
#include <exception>

class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const;
    bool empty() const;
    void push_back(const std::string &t);
    void pop_back();
    std::string& front();
    const std::string& front() const ;
    std::string& back();
    const std::string& back() const ;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check (size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif