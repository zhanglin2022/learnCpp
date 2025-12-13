// Exercise 12.15
//
// Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place 
// of the end_connection function.
//

#include <iostream>
#include <memory>
#include <string>

struct connection {
    std::string ip;
    int port;
    connection(std::string ip_, int port_): ip(ip_), port(port_) {}
};
struct destination {
    std::string ip;
    int port;
    destination(std::string ip_, int port_):ip(ip_), port(port_) {}
};

connection connect(destination* pDest) {
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn) {
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection *pConn) { 
    disconnect(*pConn); 
};

void f(destination &d) {
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, [](connection *pConn) { disconnect(*pConn); });
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main() {
    destination dest("192.168.133.83", 1243);
    f(dest);
}
