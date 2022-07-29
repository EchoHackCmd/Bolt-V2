#ifndef CLIENT_BOLT_HOOK_HOOKS_GAMEMODE_GAMEMODE
#define CLIENT_BOLT_HOOK_HOOKS_GAMEMODE_GAMEMODE

#include "../../Hook.h"

class GameMode_Hook : public Hook {
public:
    GameMode_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_GAMEMODE_GAMEMODE */