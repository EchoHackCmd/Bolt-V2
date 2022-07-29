#ifndef CLIENT_BOLT_MODULE_PLAYER_ANIM
#define CLIENT_BOLT_MODULE_PLAYER_ANIM

#include "../Module.h"

class Anim : public Module {
public:
    Anim(Category* c) : Module("Anim", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
bool LOOPAnim = false;
bool Hurtanim = false;
    auto onTick(void) -> void override;
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_PLAYER_ANIM */