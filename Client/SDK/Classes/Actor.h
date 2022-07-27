#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "../../Utils/Utils.h"

class Actor {
public:
    uintptr_t** VTable;
public:
    auto onGround(void) -> bool*;
public:
    auto setPos(Vec3<float>) -> void;
    auto getPos(void) -> Vec3<float>;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */