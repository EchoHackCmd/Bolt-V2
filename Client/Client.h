#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include "Bolt/Manager.h"

class Client {
public:
    std::string name;
public:
    Client(std::string);
public:
    auto init(void) -> void;
};

#endif /* CLIENT_CLIENT */