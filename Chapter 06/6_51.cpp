#include <iostream>
using std::cout; using std::endl;

void f()
{
	cout << "Hello World!" << endl;
}
void f(int i)
{
	cout << "Hey, I have an integer: " << i << endl;
}
void f(int i, int j)
{
	cout << "Wow, I got two integers: " << i <<  ", " << j << endl;
}
void f(double i, double j = 3.14)
{
	cout << "OMG, I GOT TWO DOUBLES: " << i << ", " << j << "!" << endl;
}

int main()
{
	f();
	// f(2.56, 42); throws ambiguity error
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}
