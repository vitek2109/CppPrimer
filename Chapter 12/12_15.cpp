#include <iostream>
#include <memory>

struct destination {};
struct connection {};
connection connect(destination* d) { std::cout << "Connected" << std::endl; }
void disconnect(connection c) { std::cout << "Disconnected" << std::endl; }

int main() {
    destination d;
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *c) { disconnect(*c); });
}