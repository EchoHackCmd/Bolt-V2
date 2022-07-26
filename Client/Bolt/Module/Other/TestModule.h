#ifndef CLIENT_BOLT_MODULE_OTHER_TESTMODULE
#define CLIENT_BOLT_MODULE_OTHER_TESTMODULE

#include "../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module("Test Module", c) {
        
        //

    };
};

#endif /* CLIENT_BOLT_MODULE_OTHER_TESTMODULE */