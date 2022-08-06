#ifndef CLIENT_SDK_CLASSES_PLAYER
#define CLIENT_SDK_CLASSES_PLAYER

#include "Actor.h"
#include "PlayerInventory.h"

class Player : public Actor {
public:
    auto getSupplies(void) -> class PlayerInventory*;
};

#endif /* CLIENT_SDK_CLASSES_PLAYER */