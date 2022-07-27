#ifndef CLIENT_BOLT_HOOK_HOOKS_KEY_KEY
#define CLIENT_BOLT_HOOK_HOOKS_KEY_KEY

#include "../../Hook.h"

class Key_Hook : public Hook {
public:
    Key_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_KEY_KEY */