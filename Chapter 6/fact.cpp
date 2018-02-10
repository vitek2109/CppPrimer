#include "Chapter6.h"

long long fact (long long n)
{
    long long res = 1;
    while (n > 1)
        res *= n--;
    return res;
}