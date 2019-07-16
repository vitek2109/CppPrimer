#ifndef STRVEC
#define STRVEC

#include <memory>
#include <string>
#include <initializer_list>

class StrVec {
public:
	StrVec() : 	// allocator has a default constructor
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<std::string>&);
	StrVec(const StrVec&);			// copy constructor
	StrVec &operator=(const StrVec&);	// copy assingment operator
	~StrVec();				// destructor
	void push_back(const std::string&);	// add element to the end
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
    void reserve(const size_t&);
    void resize(const size_t&, const std::string&);
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	std::allocator<std::string> alloc;	// reserves memory
	// used by functions that add elements
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// used to copy instances
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free(); // deletes elements and deallocates memory
	void reallocate(); // gets more memory and moves everything
	std::string *elements;		// first element
	std::string *first_free;	// first free element
	std::string *cap;		// the end of allocated memory
};

StrVec::StrVec(const StrVec &s) {
    std::pair<std::string*, std::string*> new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &lst) {
    for (const auto &e : lst)
        push_back(e);
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
	chk_n_alloc(); // now we have enough memory
	alloc.construct(first_free++, s); // make a copy of s in the first free spot
}

void StrVec::reserve(const size_t &n) {
    if (n > capacity()) {
        auto newcapacity = n;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}

void StrVec::resize(const size_t& n, const std::string& s = "") {
    while (n > size()) {
        push_back(s);
    }
    if (n < size()) {
        for (size_t i = size(); i > n; --i) {
            alloc.destroy(--first_free);
        }
    }
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);                  // allocate new memory
    return { data, uninitialized_copy(b, e, data) };    // return pair contoining pointers to the first and last elements of it
}

void StrVec::free() {
    if (elements) {         // if not empty
        for (auto p = first_free; p != elements; /*   */)   // delete everything
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);     // deallocate memory
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() : 1;       // new capaticy is twice the old one
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

#endif
