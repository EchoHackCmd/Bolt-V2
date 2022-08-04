#ifndef CLIENT_BOLT_MODULE_COMBAT_HITBOX
#define CLIENT_BOLT_MODULE_COMBAT_HITBOX

#include "../Module.h"

class Hitbox : public Module {
public:
    Hitbox(Category* c) : Module("Hitbox", c) {
        
        //

    };
public:
    auto onGameMode(GameMode*) -> void override;
    auto onDisable(void) -> void override;
private:
    std::map<uint8_t, Vec2<float>> sizes;
public:
    Vec2<float> size = Vec2<float>(2.f, 4.f);
};

#endif /* CLIENT_BOLT_MODULE_COMBAT_HITBOX */
