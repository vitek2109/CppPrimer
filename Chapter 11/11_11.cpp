#include <set>
#include "Sales_data.h"

int main() {
    std::multiset<Sales_data, bool> bookstore(compareIsbn);
}