#include <string>

using std::string;

using sTen = string[10];

sTen* arrPtr();

auto arrPointer() -> string(*)[10];

string sa[] = {"Hello", "World", "Hello", "World", "Hello", "World", "Hello", "World", "Hello", "World"};

decltype(sa) *arrayPointer();

int main() {}