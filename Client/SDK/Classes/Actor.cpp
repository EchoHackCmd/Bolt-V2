#include "Actor.h"

auto Actor::onGround(void) -> bool* {

    return (bool*)((uintptr_t)(this) + 0x1D8);
    
};