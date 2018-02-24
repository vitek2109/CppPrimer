int even[] = {0, 2, 4, 6, 8};
int odd[] = {1, 3, 5, 7, 9};

decltype(even) &arrRef(int i)
{
	return i % 2 == 0 ? even : odd;
}

int main() {}