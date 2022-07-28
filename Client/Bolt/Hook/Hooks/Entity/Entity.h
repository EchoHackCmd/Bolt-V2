#ifndef CLIENT_BOLT_HOOK_HOOKS_ENTITY_ENTITY
#define CLIENT_BOLT_HOOK_HOOKS_ENTITY_ENTITY

#include "../../Hook.h"

class Entity_Hook : public Hook {
public:
    Entity_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_ENTITY_ENTITY */