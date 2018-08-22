#ifndef STR_BLOB
#define STR_BLOB
#include <vector>
#include <string>
#include <memory>
#include <utility>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) { }
    StrBlob& operator= (const StrBlob &rhs) { data = std::make_shared<std::vector<std::string>>(*rhs.data); }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // addition and removal of elements
    void push_back(const std::string &t) const & { data->push_back(t); }
    void push_back(const std::string &t) && { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    std::string& front();
    std::string& back();
    // const versions
    const std::string& front() const;
    const std::string& back() const;
    // return pointers to the first and after-last elements of the vector
    StrBlobPtr begin();
    StrBlobPtr end();
    // const versions
    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throw an exeption if data[i] is not accessible
    void check (size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    // pointer operations
    std::string& deref() const;
    StrBlobPtr& incr(); // prefix increment
private:
    // check() returns shared_ptr to vector only if everything is fine
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const;
    // stores weak_ptr, so main vector can be deleted
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // curent position inside the vector
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    // pointer operations
    std::string& deref() const;
    ConstStrBlobPtr& incr(); // prefix increment
private:
    // check() returns shared_ptr to vector only if everything is fine
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const;
    // stores weak_ptr, so main vector can be deleted
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // curent position inside the vector
};

#endif