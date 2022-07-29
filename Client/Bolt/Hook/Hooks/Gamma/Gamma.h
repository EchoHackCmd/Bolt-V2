#ifndef CLIENT_BOLT_HOOK_HOOKS_GAMMA_ENTITY
#define CLIENT_BOLT_HOOK_HOOKS_GAMMA_ENTITY

#include "../../Hook.h"

class Gamma_Hook : public Hook {
public:
    Gamma_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_GAMMA_ENTITY */