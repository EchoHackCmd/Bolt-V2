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
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
public:
    auto onRender(void) -> void override;
    auto onGameMode(GameMode*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_OTHER_TESTMODULE */