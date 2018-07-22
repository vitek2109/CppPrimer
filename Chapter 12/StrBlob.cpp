#include "StrBlob.h"

typedef std::vector<std::string>::size_type size_type;

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

size_type StrBlob::size() const { 
    return data->size(); 
}

bool StrBlob::empty() const {
    return data->empty(); 
}

void StrBlob::push_back(const std::string &t) {
    data->push_back(t); 
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr (*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr (*this, data->size());
}

void StrBlob::check (size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back");
    data->pop_back();
}

std::string& StrBlob::front() {
    check(0, "front");
    return data->front();
}

const std::string& StrBlob::front() const {
    check(0, "front");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back");
    return data->back();
}

const std::string& StrBlob::back() const {
    check(0, "back");
    return data->back();
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("Dangling weak_ptr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "deref");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "incr");
    ++curr;
    return *this;
}