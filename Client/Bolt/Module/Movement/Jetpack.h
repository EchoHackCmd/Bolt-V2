#ifndef CLIENT_BOLT_MODULE_MOVEMENT_JETPACK
#define CLIENT_BOLT_MODULE_MOVEMENT_JETPACK

#include "../Module.h"

class Jetpack : public Module {
public:
    Jetpack(Category* c) : Module("Jetpack", c) {
        this->setKey(0x46); /* F */
    };
public:
    auto onTick(void) -> void override;
    auto onGameMode(GameMode*) -> void override;
private:
    float speed = 2.5f;
};

#endif /* CLIENT_BOLT_MODULE_MOVEMENT_JETPACK */