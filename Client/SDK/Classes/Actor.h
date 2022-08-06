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

class _ActorData {
public:
    _ActorData(Actor*);
private:
    auto setData(Actor*) -> void;
private:
    bool isHostileType = false;
    bool isPassiveType = false;
private:
    bool isItemType = false;
    bool isBlocksType = false;
    bool isProjectileOrImmobileType = false;
private:
    std::pair<uint8_t, std::string> type;
public:
    auto getType(void) -> std::pair<uint8_t, std::string>;
public:
    auto isHostile(void) -> bool;
    auto isPassive(void) -> bool;
public:
    auto isItem(void) -> bool;
    auto isBlock(void) -> bool;
    auto isImmobOrProj(void) -> bool;
};

class Actor {
public:
    uintptr_t** VTable;
public:
    auto getInfo(void) -> _ActorData;
public:
    auto isValidMob(void) -> bool;
    auto getType(void) -> std::pair<uint8_t, std::string>;
public:
    auto getLevel(void) -> Level*;
public:
    auto onGround(void) -> bool*;
    auto getSize(void) -> Vec2<float>;
    auto getStepHeight(void) -> float*;
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
    auto useItem(ItemStackBase*, ItemUseMethod, bool) -> void;
public:
    auto isWorldBuilder(void) -> bool;
    auto isInCreative(void) -> bool;
    auto isAdventure(void) -> bool;
    auto isSurvival(void) -> bool;
    auto isSpectator(void) -> bool;
    auto isAttackableGamemode(void) -> bool;
public:
    auto setSize(float, float) -> void;
public:
    auto startSpinAttack(void) -> void;
    auto setDamageNearbyMobs(bool) -> void;
public:
    auto kill(void) -> void;
    auto die(ActorDamageSource*) -> void;
    auto shouldDropDeathLoot(void) -> bool;
public:
    auto markHurt(void) -> void;
public:
    auto checkInsideBlocks(float) -> void;
    auto pushOutOfBlocks(Vec3<float>) -> void;
public:
    auto updateWaterState(void) -> bool;
    auto doWaterSplashEffect(void) -> void;
    auto spawnTrailBubbles(void) -> void;
public:
    auto updateInsideBlock(void) -> void;
};

enum EntityType {
    /* Drops */
    
    Dropped_Item = 64,
    Experience_Orb = 69,
    
    /* Blocks */
    
    TNT = 65,
    Falling_Block = 66,
    Moving_Block = 67,
    
    /* Immobile and Projectiles */
    
    Armor_Stand = 61,
    Bottle_Of_Enchanting = 68,
    Eye_Of_Ender = 70,
    Ender_Crystal = 71,
    Firework_Rocket = 72,
    Thrown_Trident = 73,
    Shulker_Bullet = 76,
    Fishing_Hook = 77,
    Dragon_Fireball = 79,
    Arrow = 80,
    Snowball = 81,
    Egg = 82,
    Painting = 83,
    Minecart = 84,
    Fireball = 85,
    Splash_Potion = 86,
    Ender_Pearl = 87,
    Leash_Knot = 88,
    Wither_Skull = 89,
    Boat = 90,
    Wither_Skull_Dangerous = 91,
    Lightning_Bolt = 93,
    Small_Fireball = 94,
    Area_Effect_Cloud = 95,
    Hopper_Minecart = 96,
    TNT_Minecart = 97,
    Chest_Minecart = 98,
    Command_Block_Minecart = 100,
    Lingering_Potion = 101,
    Llama_Spit = 102,
    Evocation_Fang = 103,
    Ice_Bomb = 106,
    Balloon = 107,
    Boat_With_Chest = 218,
    
    /* Hostile Mobs */

    Zombie = 32,
    Creeper = 33,
    Skeleton = 34,
    Spider = 35,
    Zombie_Pigman = 36,
    Slime = 37,
    Enderman = 38,
    Silverfish = 39,
    Cave_Spider = 40,
    Ghast = 41,
    Magma_Cube = 42,
    Blaze = 43,
    Zombie_Villager = 44,
    Witch = 45,
    Stray = 46,
    Husk = 47,
    Wither_Skeleton = 48,
    Guardian = 49,
    Elder_Guardian = 50,
    Wither = 52,
    Ender_Dragon = 53,
    Shulker = 54,
    Endermite = 55,
    Vindicator = 57,
    Phantom = 58,
    Ravager = 59,
    Evocation_Villager = 104,
    Vex = 105,
    Drowned = 110,
    Pillager = 114,
    Zombie_Villager_V2 = 116,
    Piglin = 123,
    Hoglin = 124,
    Zoglin = 126,
    Piglin_Brute = 127,
    Warden = 131,

    /* Passive and Neutral Mobs */

    Chicken = 10,
    Cow = 11,
    Pig = 12,
    Sheep = 13,
    Wolf = 14,
    Villager = 15,
    Mooshroom = 16,
    Squid = 17,
    Rabbit = 18,
    Bat = 19,
    Iron_Golem = 20,
    Snow_Golem = 21,
    Ocelot = 22,
    Horse = 23,
    Donkey = 24,
    Mule = 25,
    Skeleton_Horse = 26,
    Zombie_Horse = 27,
    Polar_Bear = 28,
    Llama = 29,
    Parrot = 30,
    Dolphin = 31,
    Turtle = 74,
    Cat = 75,
    Pufferfish = 108,
    Salmon = 109,
    Tropical_Fish = 111,
    Cod = 112,
    Panda = 113,
    Villager_V2 = 115,
    Wandering_Trader = 118,
    Fox = 121,
    Bee = 122,
    Strider = 125,
    Goat = 128,
    Frog = 132,
    Tadpole = 133,
    Allay = 134,

    /* Other */

    Remote_Player = 63,
    Shield = 117,
    
    /* Unused */
    Elder_Guardian_Ghost = 120,

    /* Education Edition */

    NPC = 51,
    Agent = 56,
    Tripod_Camera = 62,
    Chalkboard = 78
};

#endif /* CLIENT_SDK_CLASSES_ACTOR */