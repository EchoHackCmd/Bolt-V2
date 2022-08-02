#ifndef CLIENT_BOLT_MODULE_RENDER_TABGUI
#define CLIENT_BOLT_MODULE_RENDER_TABGUI

#include "../Module.h"

class TabGui : public Module {
public:
    TabGui(Category* c) : Module("TabGui", c) {
        this->setKey(VK_TAB); /* Set key to VK_TAB */
        this->setState(true); /* Enable by default */
    };
public:
    auto onRender(void) -> void override;
    auto onKey(uint64_t, bool, bool*) -> void override;
public:
    int iCategory = 0, iModule = 0;
    bool sCategory, sModule = false;
public:
    float iCatXOff = 0.f, iModXOff = 0.f;
public:
    float alpha = 0.f;
    auto updateAlpha(void) -> void;
    auto reachOff(float*, float, float) -> void;
};

#endif /* CLIENT_BOLT_MODULE_RENDER_TABGUI */