#include "Category.h"
#include "../Manager.h"

Category::Category(CategoryType type, Manager* mgr) {

    this->type = type;
    this->manager = mgr;

};

auto Category::getName(void) -> std::string {

    auto mgr = this->manager;
    auto res = std::string("Unknown");

    if(mgr == nullptr)
        return res;
    
    return mgr->getCategory(this->type);

};