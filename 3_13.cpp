#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::string; using std::vector;

int main()
{
    // (a)
    vector<int> v1; // = {}
    // (b)
    vector<int> v2(10); // = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    // (c)
    vector<int> v3(10, 42); // = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42}
    // (d)
    vector<int> v4{10}; // = {10}
    // (e)
    vector<int> v5{10, 42}; // = {10, 42}
    // (f) 
    vector<string> v6{10}; // = {"", "", "", "", "", "", "", "", "", ""}
    // (g)
    vector<string> v7{10, "hi"}; // = {"hi", "hi", "hi", "hi", "hi", "hi", "hi", "hi", "hi", "hi"}
}