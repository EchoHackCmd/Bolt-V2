#ifndef CLIENT_BOLT_HOOK_HOOK
#define CLIENT_BOLT_HOOK_HOOK

#include "../../Utils/Utils.h"

class Manager;

class Hook {
public:
    Manager* manager;
public:
    Hook(Manager*);
public:
    virtual auto init(void) -> void {};
};

#endif /* CLIENT_BOLT_HOOK_HOOK */