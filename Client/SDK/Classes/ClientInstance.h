#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "../../Utils/Utils.h"

class ClientInstance {
public:
    uintptr_t** VTable;
public:
    auto getLocalPlayer(void) -> uintptr_t*;
public:
    auto grabMouse(void) -> void;
    auto releaseMouse(void) -> void;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */