#include <iostream>
#include <fstream>
#include "StrBlob.h"

int main() {
    std::ifstream in("text.txt");
    StrBlob blob;
    std::string line;
    while (std::getline(in, line))
        blob.push_back(line);
    for (auto b = blob.begin(); true; b.incr())
        std::cout << b.deref() << std::endl;
    in.close();
}