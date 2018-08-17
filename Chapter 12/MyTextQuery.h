// The authors are asking to write two classes, but I'm lazy and this class is pretty small, so I'm gonna write only one
#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <vector>

class TextQuery {
public:
    TextQuery(std::ifstream& in);
    void print (std::ostream& out, std::string s);
private:
    std::vector<std::string> line_vector;
    std::map<std::string, std::set<int>> line_map;
};

void lower(std::string &s);

#endif