#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include "Bolt/Manager.h"

class Client {
public:
    std::string name;
    Manager* manager = nullptr;
public:
    Client(std::string);
public:
    auto init(void) -> void;
    auto uninject(void) -> void;
};

#endif /* CLIENT_CLIENT */