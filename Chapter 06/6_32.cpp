int &get (int *arr, int index) { return arr[index]; }

int main()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;
}