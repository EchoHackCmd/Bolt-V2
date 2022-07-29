#ifndef CLIENT_BOLT_MODULE_COMBAT_CRITICALS
#define CLIENT_BOLT_MODULE_COMBAT_CRITICALS

#include "../Module.h"

class Criticals : public Module {
public:
    Criticals(Category* c) : Module("Criticals", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_COMBAT_CRITICALS */