#ifndef CLIENT_BOLT_MODULE_MOVEMENT_NOSLOW
#define CLIENT_BOLT_MODULE_MOVEMENT_NOSLOW
#include "../Module.h"

class NoSlow : public Module {
public:
    NoSlow(Category* c) : Module("NoSlow", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_MOVEMENT_NOSLOW */