// The authors are asking to write two classes, but I'm lazy and this class is pretty small, so I'm gonna write only one
#ifndef MY_TEXT_QUERY
#define MY_TEXT_QUERY

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <vector>

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream& in);
    void print (std::ostream& out, std::string s);
private:
    std::vector<std::string> line_vector;
    std::map<std::string, std::set<line_no>> line_map;
};

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);
void lower(std::string &s);

#endif