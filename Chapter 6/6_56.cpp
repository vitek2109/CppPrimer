#include <iostream>
#include <vector>
using std::cout; using std::endl;

inline int add(int i, int j)
{
	return i + j;
}

inline int subtract(int i, int j)
{
	return i - j;
}

inline int multiply(int i, int j)
{
	return i * j;
}

inline int divide(int i, int j)
{
	return i / j;
}

std::vector<int(*)(int, int)> v = {add, subtract, multiply, divide};

int main()
{
	for (decltype(v.size()) i = 0; i < v.size(); ++i) {
		cout << v[i](6, 2) << ' ';
	}
	cout << endl;
}