#ifndef CLIENT_BOLT_MODULE_PLAYER_AUTOWEAPON
#define CLIENT_BOLT_MODULE_PLAYER_AUTOWEAPON

#include "../Module.h"

class AutoWeapon : public Module {
public:
    AutoWeapon(Category* c) : Module("AutoWeapon", c) {};
public:
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_PLAYER_AUTOWEAPON */