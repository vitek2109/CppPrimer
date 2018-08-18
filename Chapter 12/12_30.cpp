#include <fstream>
#include <string>
#include "TextQuery.h"

void runQueries(std::ifstream &in) {
    TextQuery tq(in);
    while (true) {
        std::string sought;
        std::cout << "Enter a query or 'q' to quit:" << std::endl;
        if (!(std::cin >> sought) || sought == "q") break;
        print (std::cout, tq.query(sought));
    }
}

int main() {
    std::ifstream in("text.txt");
    runQueries(in);
}