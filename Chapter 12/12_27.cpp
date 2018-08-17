#include <fstream>
#include <string>
#include "MyTextQuery.h"

void runQueries(std::ifstream &in) {
    TextQuery tq(in);
    while (true) {
        std::string query;
        std::cout << "Enter a query or 'q' to quit:" << std::endl;
        if (!(std::cin >> query) || query == "q") break;
        tq.print (std::cout, query);
    }
}

int main() {
    std::ifstream in("text.txt");
    runQueries(in);
}