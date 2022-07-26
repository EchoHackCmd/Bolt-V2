#include "Category.h"
#include "../Manager.h"
#include "../Module/Module.h"

Category::Category(CategoryType type, Manager* mgr) {

    this->type = type;
    this->manager = mgr;

};

auto Category::baseTick(void) -> void {

    for(auto mod : this->modules) {

        if(mod->isEnabled != mod->wasEnabled) {

            mod->wasEnabled = mod->isEnabled;

            if(mod->isEnabled)
                mod->onEnable();
            else
                mod->onDisable();

        };

        if(mod->isEnabled)
            mod->onTick();

    };

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

auto Category::getModule(std::string name) -> Module* {

    for(auto mod : this->modules) {

        if(mod->name.rfind(name) != std::string::npos)
            return mod;

    };

    return nullptr;

};