int main()
{
    // (a)
    int i = -1; // &r = 0;
    // (b)
    int *const p2 = &i;
    // (c)
    const int i1 = -1, &r1 = 0;
    // (d)
    const int *const p3 = &i1;
    // (e)
    const int *p1 = &i1;
    // (f)
    // const int &const r2;
    // (g)
    const int i2 = i, &r3 = i;
}
