#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

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