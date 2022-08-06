#ifndef CLIENT_BOLT_MODULE_RENDER_FULLBRIGHT
#define CLIENT_BOLT_MODULE_RENDER_FULLBRIGHT

#include "../Module.h"

class Fullbright : public Module {
public:
    Fullbright(Category* c) : Module("Fullbright", c) {
        
        //

    };
public:
    auto onGamma(float*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_RENDER_FULLBRIGHT */
