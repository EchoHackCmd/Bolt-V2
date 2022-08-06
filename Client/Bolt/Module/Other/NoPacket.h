#ifndef CLIENT_BOLT_MODULE_OTHER_NOPACKET
#define CLIENT_BOLT_MODULE_OTHER_NOPACKET

#include "../Module.h"

class NoPacket : public Module {
public:
    NoPacket(Category* c) : Module("NoPacket", c) {};
public:
    auto onPacket(Packet*, bool*) -> void override;
};

#endif /* CLIENT_BOLT_MODULE_OTHER_NOPACKET */