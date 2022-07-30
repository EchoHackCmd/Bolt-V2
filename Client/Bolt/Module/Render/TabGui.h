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
};

#endif /* CLIENT_BOLT_MODULE_RENDER_TABGUI */