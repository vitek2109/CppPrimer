#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::map<std::string, std::string> m;
    std::vector<int> v;
    std::map<std::string, std::string>::iterator fm = m.find("1");
    std::vector<int>::iterator fv = std::find(v.begin(), v.end(), 1);
}