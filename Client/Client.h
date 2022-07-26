#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include <Windows.h>
#include <string>

class Client {
public:
    std::string name;
public:
    Client(std::string);
public:
    auto init(void) -> void;
};

#endif /* CLIENT_CLIENT */