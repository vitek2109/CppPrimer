#ifndef STRING
#define STRING
#include <memory>
#include <cstring>

class String {
public:
	String() : elements(nullptr), first_free(nullptr), cap(nullptr) {};
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();
	size_t size() { return first_free - elements; }
	size_t capacity() { return cap - elements; }
	char* begin() const { return elements; }
	char* end() const { return first_free; }
private:
	std::allocator<char> alloc;
	char* elements;
	char* first_free;
	char* cap;
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
};

String::String(const char* c) {
	size_t len = strlen(c);
	auto data = alloc_n_copy(c, c+len);
	elements = data.first;
	first_free = cap = data.second;
}

String::String(const String &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	elements = data.first;
	first_free = cap = data.second;
}

String& String::operator=(const String& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::~String() {
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void String::free() {
	if (elements) {
		for (auto p = first_free; p != elements; /*   */)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

#endif
