#ifndef CLIENT_BOLT_MODULE_MODULE
#define CLIENT_BOLT_MODULE_MODULE

#include "../../Util/Util.h"

class Category;

class Module {
public:
    std::string name;
    Category* category;
public:
    uint64_t key;
    bool isEnabled = false, wasEnabled = false;
public:
    Module(std::string, Category*);
public:
    auto setState(bool) -> void;
    auto setKey(uint64_t) -> void;
public:
    virtual auto onTick(void) -> void {};
    virtual auto onEnable(void) -> void {};
    virtual auto onDisable(void) -> void {};
};

#endif /* CLIENT_BOLT_MODULE_MODULE */