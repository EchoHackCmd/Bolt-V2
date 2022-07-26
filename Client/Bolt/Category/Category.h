#ifndef CLIENT_BOLT_CATEGORY_CATEGORY
#define CLIENT_BOLT_CATEGORY_CATEGORY

#include "../../Util/Util.h"

class Manager;

enum CategoryType {
    Combat = 0,
    Movement = 1,
    Player = 2,
    Render = 3,
    World = 4
};

class Category {
private:
    CategoryType type;
    Manager* manager;
public:
    Category(CategoryType, Manager*);
public:
    auto getName(void) -> std::string;
};

#endif /* CLIENT_BOLT_CATEGORY_CATEGORY */