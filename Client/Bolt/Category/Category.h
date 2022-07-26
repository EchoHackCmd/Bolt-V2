#ifndef CLIENT_BOLT_CATEGORY_CATEGORY
#define CLIENT_BOLT_CATEGORY_CATEGORY

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
};

#endif /* CLIENT_BOLT_CATEGORY_CATEGORY */