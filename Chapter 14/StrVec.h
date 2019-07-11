#ifndef STRVEC
#define STRVEC

#include <memory>
#include <string>

class StrVec {
public:
	StrVec() : 	// allocator has a default constructor
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);			// copy constructor
	StrVec &operator=(const StrVec&);	// copy assingment operator
	~StrVec();				// destructor
	void push_back(const std::string&);	// add element to the end
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
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

void StrVec::push_back(const std::string& s) {
	chk_n_alloc(); // now we have enough memory
	alloc.construct(first_free++, s); // make a copy of s in the first free spot
}

void StrVec::reallocate() {}

#endif
