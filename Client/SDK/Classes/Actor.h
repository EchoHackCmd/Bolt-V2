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
    auto positionPassenger(Actor*,float) -> void;
    auto startRiding(Actor*) -> bool;
    auto addPassenger(Actor*) -> void;
    auto flagPassengerToRemove(Actor*) -> void;
public:
    auto intersects(Vec3<float>, Vec3<float>) -> bool;
    auto isInWall(void) -> bool;
    auto isInvisible(void) -> bool;
public:
    auto canShowNameTag(void) -> bool;
    auto setNameTagVisible(bool) -> void;
    auto getNameTag(void) -> std::string;
    auto setNameTag(std::string) -> void;
public:
    auto isInWater(void) -> bool;
    auto hasEnteredWater(void) -> bool;
    auto isInLava(void) -> bool;
    auto isUnderLiquid(enum MaterialType) -> bool;
    auto isOverWater(void) -> bool;
public:
    auto setBlockMovementSlowdownMultiplier(class BlockLegacy*, Vec3<float>) -> void;
    auto resetBlockMovementSlowdownMultiplier(void) -> void;
public:
    auto getHeadLookVector(float) -> Vec3<float>;
    auto canSee(Vec3<float>) -> bool;
    auto canSee(Actor*) -> bool;
public:
    auto isSkyLit(float) -> bool;
    auto getBrightness(float) -> float;
public:
    auto isImmobile(void) -> bool;
    auto isSilent(void) -> bool;
public:
    auto isPickable(void) -> bool;
public:
    auto isSleeping(void) -> bool;
    auto setSleeping(bool) -> void;
public:
    auto setSneaking(bool) -> void;
    auto isBlocking(void) -> bool;
public:
    auto isAlive(void) -> bool;
    auto isOnFire(void) -> bool;
    auto isOnHotBlock(void) -> bool;
public:
    auto isSurfaceMob(void) -> bool;
    auto isRemotePlayer(void) -> bool;
public:
    auto canAttack(Actor*, bool) -> bool;
    auto setTarget(Actor*) -> void;
public:
    auto getEquipmentCount(void) -> __int64;
public:
    auto getEntityTypeId(void) -> uint8_t;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */