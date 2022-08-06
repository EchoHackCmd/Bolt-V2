#include "MinecraftGame.h"

auto MinecraftGame::canUseKeys(void) -> bool {

    return *(bool*)((uintptr_t)(this) + 0xC8);

};

auto MinecraftGame::mcFont(void) -> Font* {

    return *(Font**)((uintptr_t)(this) + 0xE78);

};