#ifndef CLIENT_BOLT_MANAGER
#define CLIENT_BOLT_MANAGER

#include "../Util/Util.h"

class Client;
class Category;
enum CategoryType;

class Manager {
private:
    Client* client = nullptr;
public:
    auto initModules(void) -> void;
public:
    Manager(Client*);
public:
    std::map<int, Category*> categories;
    auto initCategories(void) -> void;
public:
    auto initHooks(void) -> void;
public:
    auto getCategory(CategoryType) -> std::string;
};

#endif /* CLIENT_BOLT_MANAGER */