#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

void print (const vector<int> &v, int index = 0)
{
	cout << v[index] << ' ';
	if (index != v.size() - 1)
		print(v, index + 1);
	if (index == 0)
		cout << endl;
}

int main()
{
	vector<int> v = {0, 1, 2, 3, 4};
	print(v);
}