#ifndef CLIENT_BOLT_MANAGER
#define CLIENT_BOLT_MANAGER
#include "../Client.h"
class Manager {
private:
    Client* client = nullptr;
public:
    auto initModules(void) -> void;
public:
    Manager(Client*);
public:
    auto initCategories(void) -> void;
public:
    auto initHooks(void) -> void;
};

#endif /* CLIENT_BOLT_MANAGER */