#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"

class Actor {
public:
    uintptr_t** VTable;
public:
    auto getLevel(void) -> Level*;
public:
    auto onGround(void) -> bool*;
    auto getRuntimeId(void) -> uint64_t;
public:
    auto setPos(Vec3<float>) -> void;
    auto getPos(void) -> Vec3<float>;
public:
    auto getFiringPos(void) -> Vec3<float>;
    auto setRot(Vec2<float>) -> void;
public:
    auto isFireImmune(void) -> bool;
    auto canDisableShield(void) -> bool;
public:
    auto teleportTo(Vec3<float>, bool, int, int, bool) -> void;
    auto tryTeleportTo(Vec3<float>, bool, bool, int, int) -> void;
    auto chorusFruitTeleport(Vec3<float>) -> void;
public:
    auto lerpMotion(Vec3<float>) -> void;
public:
    auto getEntityTypeId(void) -> uint8_t;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */