#ifndef CLIENT_BOLT_MANAGER
#define CLIENT_BOLT_MANAGER

#include "../Util/Util.h"

class Client;

class Hook;
class Category;
enum CategoryType;

class Manager {
private:
    Client* client = nullptr;
    bool isRunning = false;
public:
    std::vector<Hook*> hooks;
    auto initHooks(void) -> void;
public:
    Manager(Client*);
public:
    std::map<int, Category*> categories;
    auto initCategories(void) -> void;
    auto getCategory(CategoryType) -> std::pair<std::string, Category*>;
public:
    auto initModules(void) -> void;
public:
    auto baseTick(void) -> void;
};

#endif /* CLIENT_BOLT_MANAGER */