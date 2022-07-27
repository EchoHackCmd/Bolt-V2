#include "MinecraftGame.h"

auto MinecraftGame::canUseKeys(void) -> bool {

    return *(bool*)((uintptr_t)(this) + 0xC8);

};