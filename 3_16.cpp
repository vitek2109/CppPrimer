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
    
    cout << "v1: " <<  v1.size() << endl;
    for (auto e : v1)
        cout << e << " ";
    cout << endl;
    cout << "v2: " <<  v2.size() << endl;
    for (auto e : v2)
        cout << e << " ";
    cout << endl;
        cout << "v3: " <<  v3.size() << endl;
    for (auto e : v3)
        cout << e << " ";
    cout << endl;
        cout << "v4: " <<  v4.size() << endl;
    for (auto e : v4)
        cout << e << " ";
    cout << endl;
        cout << "v5: " <<  v5.size() << endl;
    for (auto e : v5)
        cout << e << " ";
    cout << endl;
        cout << "v6: " <<  v6.size() << endl;
    for (auto e : v6)
        cout << e << " ";
    cout << endl;
        cout << "v7: " <<  v7.size() << endl;
    for (auto e : v7)
        cout << e << " ";
    cout << endl;
}