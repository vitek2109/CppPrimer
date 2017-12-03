#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
    // (a)
    vector<vector<int>> ivec;
    // (b)
    // error: cannot copy vector containing a different type
    // vector<string> svec = ivec;
    // (c)
    vector<string> svec(10, "null");
}