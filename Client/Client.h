#ifndef CLIENT_CLIENT
#define CLIENT_CLIENT

#include "Bolt/Manager.h"
#include <string>

class Client {
public:
    std::string name;
    Manager* manager = nullptr;
public:
    Client(std::string);
public:
    auto init(void) -> void;
};

#endif /* CLIENT_CLIENT */