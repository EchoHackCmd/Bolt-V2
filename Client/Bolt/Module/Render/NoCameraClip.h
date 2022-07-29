#ifndef CLIENT_BOLT_MODULE_RENDER_NOCAMERACLIP
#define CLIENT_BOLT_MODULE_RENDER_NOCAMERACLIP

#include "../Module.h"

class NoCameraClip : public Module {
public:
    NoCameraClip(Category* c) : Module("NoCameraClip", c) {
        
        this->setState(false); /* Disable by default */

    };
public:
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_RENDER_NOCAMERACLIP */