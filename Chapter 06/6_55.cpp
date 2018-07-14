#include <vector>

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

int main() {}