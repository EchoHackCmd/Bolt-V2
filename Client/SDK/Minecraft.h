#ifndef CLIENT_SDK_MINECRAFT
#define CLIENT_SDK_MINECRAFT

#include "Classes/ClientInstance.h"

class Minecraft {
private:
    static ClientInstance* clientInstance;
public:
    static auto setClientInstance(ClientInstance*) -> void;
    static auto getClientInstance(void) -> ClientInstance*;
};

#endif /* CLIENT_SDK_MINECRAFT */