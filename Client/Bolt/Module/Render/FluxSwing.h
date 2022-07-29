#ifndef CLIENT_BOLT_MODULE_RENDER_FLUXSWING
#define CLIENT_BOLT_MODULE_RENDER_FLUXSWING

#include "../Module.h"

class FluxSwing : public Module {
public:
    FluxSwing(Category* c) : Module("FluxSwing", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_COMBAT_CRITICALS */