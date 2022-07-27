#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "../../Utils/Utils.h"

#include "MinecraftGame.h"
#include "Player.h"

class ClientInstance {
public:
    uintptr_t** VTable;
public:
    auto getMinecraftGame(void) -> class MinecraftGame*;
    auto getLocalPlayer(void) -> class Player*;
public:
    auto grabMouse(void) -> void;
    auto releaseMouse(void) -> void;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */