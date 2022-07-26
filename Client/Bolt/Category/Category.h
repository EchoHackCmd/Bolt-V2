#ifndef CLIENT_BOLT_CATEGORY_CATEGORY
#define CLIENT_BOLT_CATEGORY_CATEGORY

#include "../Module/Module.h"

class Manager;

enum CategoryType {
    Combat = 0,
    Movement = 1,
    Player = 2,
    Render = 3,
    World = 4,
    Other = 5
};

class Category {
public:
    CategoryType type;
    Manager* manager;
public:
    std::vector<Module*> modules;
public:
    Category(CategoryType, Manager*);
public:
    auto baseTick(void) -> void;
public:
    auto getName(void) -> std::string;
    auto addModule(Module*) -> void;
};

#endif /* CLIENT_BOLT_CATEGORY_CATEGORY */