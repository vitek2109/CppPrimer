#include <iostream>

int main() {
    size_t size = 1024;
    char *a = new char[size];
    for (int i = 0; i < size; ++i)
        a[i] = '\0';
    std::cin >> a;
    for (int i = 0; i < size; ++i) {
        std::cout << a[i];
        if (!a[i])
            break;
    }
    std::cout << std::endl;
    delete [] a;
}