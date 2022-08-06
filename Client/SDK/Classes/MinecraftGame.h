#ifndef CLIENT_SDK_CLASSES_MINECRAFTGAME
#define CLIENT_SDK_CLASSES_MINECRAFTGAME

#include "../../Utils/Utils.h"

class MinecraftGame {
public:
    auto canUseKeys(void) -> bool;
    auto mcFont(void) -> class Font*;
};

#endif /* CLIENT_SDK_CLASSES_MINECRAFTGAME */