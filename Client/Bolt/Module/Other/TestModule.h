#ifndef CLIENT_BOLT_MODULE_OTHER_TESTMODULE
#define CLIENT_BOLT_MODULE_OTHER_TESTMODULE

#include "../Module.h"

class TestModule : public Module {
public:
    TestModule(Category* c) : Module("Test Module", c) {
        
        this->setState(true); /* Enable by default */

    };
public:
    /* Events handled by DLL - Not by hooks */
    auto onTick(void) -> void override;
    auto onEnable(void) -> void override;
    auto onDisable(void) -> void override;
public:
    /* Events handled by hooks */
    auto onRender(void) -> void override;
    auto onGamma(float*) -> void override;
    auto onGameMode(GameMode*) -> void override;
    auto onPacket(Packet*, bool*) -> void override;
    auto onKey(uint64_t, bool, bool*) -> void override;
    auto onRenderCtx(MinecraftUIRenderContext*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_OTHER_TESTMODULE */