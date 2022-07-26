#ifndef CLIENT_BOLT_MODULE_MODULE
#define CLIENT_BOLT_MODULE_MODULE

#include "../../Util/Util.h"

class Category;

class Module {
public:
    std::string name;
    Category* category;
public:
    Module(std::string, Category*);
};

#endif /* CLIENT_BOLT_MODULE_MODULE */