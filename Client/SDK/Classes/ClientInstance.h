#ifndef CLIENT_SDK_CLASSES_CLIENTINSTANCE
#define CLIENT_SDK_CLASSES_CLIENTINSTANCE

#include "../../Utils/Utils.h"

#include "LoopbackPacketSender.h"
#include "MinecraftGame.h"
#include "GuiData.h"
#include "Player.h"

class ClientInstance {
public:
    uintptr_t** VTable;
public:
    auto getMinecraftGame(void) -> class MinecraftGame*;
    auto getGuiData(void) -> class GuiData*;
public:
    auto getLocalPlayer(void) -> class Player*;
public:
    auto grabMouse(void) -> void;
    auto releaseMouse(void) -> void;
};

#endif /* CLIENT_SDK_CLASSES_CLIENTINSTANCE */