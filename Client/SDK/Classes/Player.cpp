#include "Player.h"

auto Player::getSupplies(void) -> PlayerInventory* {

    return *(PlayerInventory**)((uintptr_t)(this) + 0xE68);

};