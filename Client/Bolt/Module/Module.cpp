#include "Module.h"
#include "../Manager.h"
#include "../Category/Category.h"

Module::Module(std::string name, Category* category) {

    this->name = name;
    this->category = category;
    this->category->addModule(this);

};