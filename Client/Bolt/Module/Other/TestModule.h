#ifndef CLIENT_BOLT_MODULE_OTHER_TESTMODULE
#define CLIENT_BOLT_MODULE_OTHER_TESTMODULE

#include "../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module("Test Module", c) {
        
        this->setState(true); /* Enable by default */

    };
public:
    auto onTick(void) -> void override;
private:
    int tickInt = 0;
};

#endif /* CLIENT_BOLT_MODULE_OTHER_TESTMODULE */