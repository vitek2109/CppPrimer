int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *b = a, *e = a + 10;
    for (b; b != e; b++)
        *b = 0;
}