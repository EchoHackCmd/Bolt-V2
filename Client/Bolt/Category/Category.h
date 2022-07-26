#ifndef CLIENT_BOLT_CATEGORY_CATEGORY
#define CLIENT_BOLT_CATEGORY_CATEGORY

enum class CategoryType {
    Combat = 0,
    Movement = 1,
    Player = 2,
    Render = 3,
    World = 4
};

class Category {
private:
    CategoryType type;
public:
    Category(CategoryType);
};

#endif /* CLIENT_BOLT_CATEGORY_CATEGORY */