#ifndef CLIENT_BOLT_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE
#define CLIENT_BOLT_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE

#include "../../Hook.h"

class ClientInstance_Hook : public Hook {
public:
    ClientInstance_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_CLIENTINSTANCE_CLIENTINSTANCE */