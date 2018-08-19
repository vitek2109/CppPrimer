#include "StrBlob.h"

typedef std::vector<std::string>::size_type size_type;

// ----------------------------StrBlob Implementation----------------------------

// constructors
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check (size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

// element access
std::string& StrBlob::front() {
    check (0, "front() on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back() {
    check (0, "back() on empty StrBlob");
    return data->back();
}
// const versions
const std::string& StrBlob::front() const {
    check (0, "front() on empty StrBlob");
    return data->front();
}
const std::string& StrBlob::back() const {
    check (0, "back() on empty StrBlob");
}

// element revomal
void StrBlob::pop_back() {
    check(0, "pop_back() on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}
ConstStrBlobPtr StrBlob::cbegin() {
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() {
    return ConstStrBlobPtr(*this, data->size());
}


// ----------------------------StrBlobPtr Implementation----------------------------

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock(); // does vector still exist
    if (!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // else return shared_ptr to vector
}

// pointer operations
std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p) is the vector, which this object points to
}
// prefix: return reference to this object after increment
StrBlobPtr& StrBlobPtr::incr() {
    // if curr is at the end, then throw an exeption
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


// ----------------------------ConstStrBlobPtr Implementation----------------------------

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock(); // does vector still exist
    if (!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // else return shared_ptr to vector
}

// pointer operations
std::string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p) is the vector, which this object points to
}
// prefix: return reference to this object after increment
ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    // if curr is at the end, then throw an exeption
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}