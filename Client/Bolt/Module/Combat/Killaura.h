#ifndef CLIENT_BOLT_MODULE_COMBAT_KILLAURA
#define CLIENT_BOLT_MODULE_COMBAT_KILLAURA

#include "../Module.h"

class Killaura : public Module {
public:
    Killaura(Category* c) : Module("Killaura", c) {
        //
    };
public:
    auto onGameMode(GameMode*) -> void override;
private:
    float range = 12.f;
};

#endif /* CLIENT_BOLT_MODULE_COMBAT_KILLAURA */
