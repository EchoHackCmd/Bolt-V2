#ifndef CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER
#define CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER

#include "Packet.h"

class LoopbackPacketSender {
private:
    virtual ~LoopbackPacketSender();
public:
    virtual auto send(Packet*) -> void;
    virtual auto sendToServer(Packet* packet) -> void; //cba to finish

};

#endif /* CLIENT_SDK_CLASSES_LOOPBACKPACKETSENDER */