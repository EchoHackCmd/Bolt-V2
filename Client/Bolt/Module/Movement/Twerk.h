#ifndef CLIENT_BOLT_MODULE_MOVEMENT_TWERK
#define CLIENT_BOLT_MODULE_MOVEMENT_TWERK

#include "../Module.h"

class Twerk : public Module {
public:
    Twerk(Category* c) : Module("Twerk", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_MOVEMENT_TWERK */