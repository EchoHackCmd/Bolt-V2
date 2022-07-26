#ifndef CLIENT_BOLT_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN
#define CLIENT_BOLT_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN

#include "../../Hook.h"

class SwapChain_Hook : public Hook {
public:
    SwapChain_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN */