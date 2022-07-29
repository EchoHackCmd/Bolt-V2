#ifndef CLIENT_BOLT_MODULE_MOVEMENT_TWERK
#define CLIENT_BOLT_MODULE_MOVEMENT_TWERK

#include "../Module.h"

class Twerk : public Module {
public:
    Twerk(Category* c) : Module("Twerk", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onTick(void) -> void override;
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
public:
    auto onRender(void) -> void override;
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_MOVEMENT_TWERK */