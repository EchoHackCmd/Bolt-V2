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
    
    return mgr->getCategory(this->type).first;

};

auto Category::addModule(Module* mod) -> void {

    if(std::find(this->modules.begin(), this->modules.end(), mod) != this->modules.end())
        return Util::debugLog("Module has already been added to this Category!");
    
    return this->modules.push_back(mod);

};