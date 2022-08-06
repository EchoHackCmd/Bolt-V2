#ifndef CLIENT_BOLT_MODULE_MOVEMENT_STEP
#define CLIENT_BOLT_MODULE_MOVEMENT_STEP

#include "../Module.h"

class Step : public Module {
public:
    Step(Category* c) : Module("Step", c) {};
public:
    auto onGameMode(GameMode*) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_MOVEMENT_STEP */