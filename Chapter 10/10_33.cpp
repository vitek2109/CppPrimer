#include <iostream>
#include <iterator>
#include <fstream>

int main(int argc, char *argv[]) {
    std::ifstream infile(argv[1]);
    std::ofstream outfile0(argv[2]), outfile1(argv[3]);
    std::istream_iterator<int> in(infile), eof;
    std::ostream_iterator<int> out0(outfile0, " "), out1(outfile1, "\n");
    while (in != eof) {
        int i = *in++;
        if (i % 2)
            *out1++ = i;
        else 
            *out0++ = i;
    }
    outfile1.close();
    outfile0.close();
    infile.close();
}