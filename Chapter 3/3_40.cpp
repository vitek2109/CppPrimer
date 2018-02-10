#include <cstring>
#include <iterator>
using std::begin; using std::end;
int main()
{
    const char s1[] = "Hello";
    const char s2[] = "World";
    constexpr auto s1_size = end(s1) - begin(s1);
    constexpr auto s2_size = end(s2) - begin(s2);
    constexpr auto s3_size = s1_size + s2_size;
    char s3[s3_size];
    strcpy(s3, s1);
    strcat(s3, s2);
}