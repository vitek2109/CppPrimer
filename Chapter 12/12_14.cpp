#include <iostream>
#include <memory>

struct destination {};
struct connection {};
connection connect(destination* d) { std::cout << "Connected" << std::endl; }
void disconnect(connection c) { std::cout << "Disconnected" << std::endl; }

void end_connection(connection *c) {
    disconnect(*c);
}

int main() {
    destination d;
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection);
}