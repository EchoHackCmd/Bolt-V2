#ifndef CLIENT_BOLT_MODULE_PLAYER_ANIM
#define CLIENT_BOLT_MODULE_PLAYER_ANIM

#include "../Module.h"

class Anim : public Module {
public:
    Anim(Category* c) : Module("Anim", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    bool LOOPAnim = false, Hurtanim = false;
public:
    auto onGameMode(GameMode*) -> void override;
    auto onEnable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_PLAYER_ANIM */