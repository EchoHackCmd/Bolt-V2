#ifndef CLIENT_BOLT_HOOK_HOOKS_PACKET_PACKET
#define CLIENT_BOLT_HOOK_HOOKS_PACKET_PACKET

#include "../../Hook.h"

class Packet_Hook : public Hook {
public:
    Packet_Hook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_BOLT_HOOK_HOOKS_PACKET_PACKET */