#ifndef CLIENT_BOLT_MODULE_OTHER_UNINJECT
#define CLIENT_BOLT_MODULE_OTHER_UNINJECT

#include "../Module.h"

class Uninject : public Module {
public:
    Uninject(Category* c) : Module("Uninject", c) {

        //

    };
public:
    auto onEnable(void) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_OTHER_UNINJECT */
