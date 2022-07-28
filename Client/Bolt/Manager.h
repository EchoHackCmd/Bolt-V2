#ifndef CLIENT_BOLT_MANAGER
#define CLIENT_BOLT_MANAGER

#include "../Utils/Utils.h"
#include "../SDK/Minecraft.h"

class Client;

class Hook;
class Category;
enum CategoryType;

class Manager {
public:
    Client* client = nullptr;
public:
    bool isRunning = false;
    std::map<std::string, ImFont*> fonts;
public:
    std::vector<Hook*> hooks;
    auto initHooks(void) -> void;
public:
    Manager(Client*);
public:
    std::map<CategoryType, Category*> categories;
public:
    auto initCategories(void) -> void;
    auto getCategory(CategoryType) -> std::pair<std::string, Category*>;
public:
    auto initModules(void) -> void;
public:
    auto baseTick(void) -> void;
public:
    std::map<uint64_t, bool> keyMap;
    auto isUsingKey(uint64_t) -> bool;
public:
    std::map<uint8_t, Actor*> entityMap;
    auto cleanEntityMap(void) -> void;
};

#endif /* CLIENT_BOLT_MANAGER */