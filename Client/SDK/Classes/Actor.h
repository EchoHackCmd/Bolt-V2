#ifndef CLIENT_SDK_CLASSES_ACTOR
#define CLIENT_SDK_CLASSES_ACTOR

#include "Level.h"
#include "GameMode.h"

enum class ActorDamageCause;

enum ArmorSlot {
    Helmet = 0,
    Chestplate = 1,
    Leggings = 2,
    Boots = 3
};

class ItemStack;
class Player;

class ItemStackBase;

enum ItemUseMethod {

    EquipArmor = 0,
    Eat = 1,
    Attack = 2,
    Consume = 3,
    Throw = 4,
    Shoot = 5,
    Place = 6,
    Fill_Bottle = 7,
    Fill_Bucket = 8,
    Pour_Bucket = 9,
    Use_Tool = 10,
    Interact = 11,
    Retrieved = 12,
    Dyed = 13,
    Traded = 14

};

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
    auto setOwner(uint64_t) -> void;
public:
    auto setSitting(bool) -> void;
    auto setStanding(bool) -> void;
public:
    auto getInventorySize(void) -> __int64;
    auto getEquipSlots(void) -> __int64;
    auto getChestSlots(void) -> __int64;
public:
    auto canPowerJump(void) -> bool;
    auto setCanPowerJump(bool) -> void;
    auto isJumping(void) -> bool;
public:
    auto isInvulnerableTo(struct ActorDamageSource*) -> bool;
    auto getBlockDamageCause(class Block*) -> ActorDamageCause;
public:
    auto animateHurt(void) -> void;
    auto doFireHurt(int) -> void;
public:
    auto feed(int) -> void;
    auto getPickRadius(void) -> float;
public:
    auto setCarriedItem(ItemStack*) -> void;
    auto getCarriedItem(void) -> ItemStack*;
public:
    auto setOffhandSlot(ItemStack*) -> void;
    auto getEquippedTotem(void) -> ItemStack*;
    auto consumeTotem(void) -> void;
public:
    auto getEntityTypeId(void) -> uint8_t;
public:
    auto checkFallDamage(float, bool) -> void;
    auto causeFallDamage(float,float, ActorDamageSource&) -> void;
    auto handleFallDistanceOnServer(float, float, bool) -> void;
public:
    auto canAddPassenger(Actor*) -> bool;
    auto inCaravan(void) -> bool;
public:
    auto sendMotionPacketIfNeeded(void) -> void;
public:
    auto stopRiding(bool, bool, bool) -> void;
public:
    auto startSwimming(void) -> void;
    auto stopSwimming(void) -> void;
public:
    auto isClientSide(void) -> bool;
public:
    auto heal(int) -> void;
public:
    auto isInvertedHealAndHarm(void) -> bool;
public:
    auto openContainerComponent(Player*) -> void;
public:
    auto swing(void) -> void;
    auto useItem(ItemStackBase&, ItemUseMethod, bool) -> void;
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */