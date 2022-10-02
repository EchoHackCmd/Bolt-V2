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
    float range = 12.f; /*       Range in proximity of attacks        */
    int cpt = 2;        /*       Clicks per tick                      */
private:
    std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now();
    int msDelay = 50;
};

#endif /* CLIENT_BOLT_MODULE_COMBAT_KILLAURA */
