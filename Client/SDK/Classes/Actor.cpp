#include "Actor.h"

_ActorData::_ActorData(Actor* entity) {

    this->setData(entity);

};

auto _ActorData::setData(Actor* entity) -> void {
    
    auto type = entity->getEntityTypeId();

    switch(type) {

        case EntityType::Dropped_Item:
            
            this->type = std::pair<uint8_t, std::string>(type, "Dropped Item");
            this->isItemType = true;

        break;

        case EntityType::Experience_Orb:

            this->type = std::pair<uint8_t, std::string>(type, "Experience Orb");
            this->isItemType = true;
        
        break;
        
        
        //

        
        case EntityType::TNT:

            this->type = std::pair<uint8_t, std::string>(type, "TNT");
            this->isBlocksType = true;
        
        break;

        case EntityType::Falling_Block:

            this->type = std::pair<uint8_t, std::string>(type, "Falling Block");
            this->isBlocksType = true;
        
        break;

        case EntityType::Moving_Block:

            this->type = std::pair<uint8_t, std::string>(type, "Moving Block");
            this->isBlocksType = true;
        
        break;


        //


        case EntityType::Armor_Stand:

            this->type = std::pair<uint8_t, std::string>(type, "Armor Stand");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Bottle_Of_Enchanting:

            this->type = std::pair<uint8_t, std::string>(type, "Bottle o' Enchanting");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Eye_Of_Ender:

            this->type = std::pair<uint8_t, std::string>(type, "Eye Of Ender");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Ender_Crystal:

            this->type = std::pair<uint8_t, std::string>(type, "Ender Crystal");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Firework_Rocket:

            this->type = std::pair<uint8_t, std::string>(type, "Firework Rocket");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Thrown_Trident:

            this->type = std::pair<uint8_t, std::string>(type, "Thrown Triden");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Shulker_Bullet:

            this->type = std::pair<uint8_t, std::string>(type, "Shulker Bullet");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Fishing_Hook:

            this->type = std::pair<uint8_t, std::string>(type, "Fishing Hook");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Dragon_Fireball:

            this->type = std::pair<uint8_t, std::string>(type, "Dragon Fireball");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Arrow:

            this->type = std::pair<uint8_t, std::string>(type, "Arrow");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Snowball:

            this->type = std::pair<uint8_t, std::string>(type, "Snowball");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Egg:

            this->type = std::pair<uint8_t, std::string>(type, "Egg");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Painting:

            this->type = std::pair<uint8_t, std::string>(type, "Painting");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Minecart:

            this->type = std::pair<uint8_t, std::string>(type, "Minecart");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Fireball:

            this->type = std::pair<uint8_t, std::string>(type, "Fireball");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Splash_Potion:

            this->type = std::pair<uint8_t, std::string>(type, "Splash Potion");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Ender_Pearl:

            this->type = std::pair<uint8_t, std::string>(type, "Ender Pearl");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Leash_Knot:

            this->type = std::pair<uint8_t, std::string>(type, "Leash Knot");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Wither_Skull:

            this->type = std::pair<uint8_t, std::string>(type, "Wither Skull");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Boat:

            this->type = std::pair<uint8_t, std::string>(type, "Boat");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Wither_Skull_Dangerous:

            this->type = std::pair<uint8_t, std::string>(type, "Blue Wither Skull");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Lightning_Bolt:

            this->type = std::pair<uint8_t, std::string>(type, "Lightning Bolt");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Small_Fireball:

            this->type = std::pair<uint8_t, std::string>(type, "Small Fireball");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Area_Effect_Cloud:

            this->type = std::pair<uint8_t, std::string>(type, "Area Effect Cloud");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Hopper_Minecart:

            this->type = std::pair<uint8_t, std::string>(type, "Hopper Minecart");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::TNT_Minecart:

            this->type = std::pair<uint8_t, std::string>(type, "TNT Minecart");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Chest_Minecart:

            this->type = std::pair<uint8_t, std::string>(type, "Chest Minecart");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Command_Block_Minecart:

            this->type = std::pair<uint8_t, std::string>(type, "Command Block Minecart");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Lingering_Potion:

            this->type = std::pair<uint8_t, std::string>(type, "Lingering Potion");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Llama_Spit:

            this->type = std::pair<uint8_t, std::string>(type, "Llama Spit");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Evocation_Fang:

            this->type = std::pair<uint8_t, std::string>(type, "Evocation Fang");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Ice_Bomb:

            this->type = std::pair<uint8_t, std::string>(type, "Ice Bomb");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Balloon:

            this->type = std::pair<uint8_t, std::string>(type, "Balloon");
            this->isProjectileOrImmobileType = true;
        
        break;

        case EntityType::Boat_With_Chest:

            this->type = std::pair<uint8_t, std::string>(type, "Boat With Chest");
            this->isProjectileOrImmobileType = true;
        
        break;


        //
        

        case EntityType::Zombie:

            this->type = std::pair<uint8_t, std::string>(type, "Zombie");
            this->isHostileType = true;
        
        break;

        case EntityType::Creeper:

            this->type = std::pair<uint8_t, std::string>(type, "Creeper");
            this->isHostileType = true;
        
        break;

        case EntityType::Skeleton:

            this->type = std::pair<uint8_t, std::string>(type, "Skeleton");
            this->isHostileType = true;
        
        break;

        case EntityType::Spider:

            this->type = std::pair<uint8_t, std::string>(type, "Spider");
            this->isHostileType = true;
        
        break;

        case EntityType::Zombie_Pigman:

            this->type = std::pair<uint8_t, std::string>(type, "Zombie Pigman");
            this->isHostileType = true;
        
        break;

        case EntityType::Slime:

            this->type = std::pair<uint8_t, std::string>(type, "Slime");
            this->isHostileType = true;
        
        break;

        case EntityType::Enderman:

            this->type = std::pair<uint8_t, std::string>(type, "Enderman");
            this->isHostileType = true;
        
        break;

        case EntityType::Silverfish:

            this->type = std::pair<uint8_t, std::string>(type, "Silverfish");
            this->isHostileType = true;
        
        break;

        case EntityType::Cave_Spider:

            this->type = std::pair<uint8_t, std::string>(type, "Cave Spider");
            this->isHostileType = true;
        
        break;

        case EntityType::Ghast:

            this->type = std::pair<uint8_t, std::string>(type, "Ghast");
            this->isHostileType = true;
        
        break;

        case EntityType::Magma_Cube:

            this->type = std::pair<uint8_t, std::string>(type, "Magma Cube");
            this->isHostileType = true;
        
        break;

        case EntityType::Blaze:

            this->type = std::pair<uint8_t, std::string>(type, "Blaze");
            this->isHostileType = true;
        
        break;

        case EntityType::Zombie_Villager:

            this->type = std::pair<uint8_t, std::string>(type, "Zombie Villager");
            this->isHostileType = true;
        
        break;

        case EntityType::Witch:

            this->type = std::pair<uint8_t, std::string>(type, "Witch");
            this->isHostileType = true;
        
        break;

        case EntityType::Stray:

            this->type = std::pair<uint8_t, std::string>(type, "Stray");
            this->isHostileType = true;
        
        break;

        case EntityType::Husk:

            this->type = std::pair<uint8_t, std::string>(type, "Husk");
            this->isHostileType = true;
        
        break;

        case EntityType::Wither_Skeleton:

            this->type = std::pair<uint8_t, std::string>(type, "Wither Skeleton");
            this->isHostileType = true;
        
        break;

        case EntityType::Guardian:

            this->type = std::pair<uint8_t, std::string>(type, "Guardian");
            this->isHostileType = true;
        
        break;

        case EntityType::Elder_Guardian:

            this->type = std::pair<uint8_t, std::string>(type, "Elder Guardian");
            this->isHostileType = true;
        
        break;

        case EntityType::Wither:

            this->type = std::pair<uint8_t, std::string>(type, "Wither");
            this->isHostileType = true;
        
        break;

        case EntityType::Ender_Dragon:

            this->type = std::pair<uint8_t, std::string>(type, "Ender Dragon");
            this->isHostileType = true;
        
        break;

        case EntityType::Shulker:

            this->type = std::pair<uint8_t, std::string>(type, "Shulker");
            this->isHostileType = true;
        
        break;

        case EntityType::Endermite:

            this->type = std::pair<uint8_t, std::string>(type, "Endermite");
            this->isHostileType = true;
        
        break;

        case EntityType::Vindicator:

            this->type = std::pair<uint8_t, std::string>(type, "Vindicator");
            this->isHostileType = true;
        
        break;

        case EntityType::Phantom:

            this->type = std::pair<uint8_t, std::string>(type, "Phantom");
            this->isHostileType = true;
        
        break;

        case EntityType::Ravager:

            this->type = std::pair<uint8_t, std::string>(type, "Ravager");
            this->isHostileType = true;
        
        break;

        case EntityType::Evocation_Villager:

            this->type = std::pair<uint8_t, std::string>(type, "Evocation Villager");
            this->isHostileType = true;
        
        break;

        case EntityType::Vex:

            this->type = std::pair<uint8_t, std::string>(type, "Vex");
            this->isHostileType = true;
        
        break;

        case EntityType::Drowned:

            this->type = std::pair<uint8_t, std::string>(type, "Drowned");
            this->isHostileType = true;
        
        break;

        case EntityType::Pillager:

            this->type = std::pair<uint8_t, std::string>(type, "Pillager");
            this->isHostileType = true;
        
        break;

        case EntityType::Zombie_Villager_V2:

            this->type = std::pair<uint8_t, std::string>(type, "Zombie Villager");
            this->isHostileType = true;
        
        break;

        case EntityType::Piglin:

            this->type = std::pair<uint8_t, std::string>(type, "Piglin");
            this->isHostileType = true;
        
        break;

        case EntityType::Hoglin:

            this->type = std::pair<uint8_t, std::string>(type, "Hoglin");
            this->isHostileType = true;
        
        break;

        case EntityType::Zoglin:

            this->type = std::pair<uint8_t, std::string>(type, "Zoglin");
            this->isHostileType = true;
        
        break;

        case EntityType::Piglin_Brute:

            this->type = std::pair<uint8_t, std::string>(type, "Piglin Brute");
            this->isHostileType = true;
        
        break;

        case EntityType::Warden:

            this->type = std::pair<uint8_t, std::string>(type, "Warden");
            this->isHostileType = true;
        
        break;


        //


        case EntityType::Chicken:

            this->type = std::pair<uint8_t, std::string>(type, "Chicken");
            this->isPassiveType = true;
        
        break;

        case EntityType::Cow:

            this->type = std::pair<uint8_t, std::string>(type, "Cow");
            this->isPassiveType = true;
        
        break;

        case EntityType::Pig:

            this->type = std::pair<uint8_t, std::string>(type, "Pig");
            this->isPassiveType = true;
        
        break;

        case EntityType::Sheep:

            this->type = std::pair<uint8_t, std::string>(type, "Sheep");
            this->isPassiveType = true;
        
        break;

        case EntityType::Wolf:

            this->type = std::pair<uint8_t, std::string>(type, "Wolf");
            this->isPassiveType = true;
        
        break;

        case EntityType::Villager:

            this->type = std::pair<uint8_t, std::string>(type, "Villager");
            this->isPassiveType = true;
        
        break;

        case EntityType::Mooshroom:

            this->type = std::pair<uint8_t, std::string>(type, "Mooshroom");
            this->isPassiveType = true;
        
        break;

        case EntityType::Squid:

            this->type = std::pair<uint8_t, std::string>(type, "Squid");
            this->isPassiveType = true;
        
        break;

        case EntityType::Rabbit:

            this->type = std::pair<uint8_t, std::string>(type, "Rabbit");
            this->isPassiveType = true;
        
        break;

        case EntityType::Bat:

            this->type = std::pair<uint8_t, std::string>(type, "Bat");
            this->isPassiveType = true;
        
        break;

        case EntityType::Iron_Golem:

            this->type = std::pair<uint8_t, std::string>(type, "Iron Golem");
            this->isPassiveType = true;
        
        break;

        case EntityType::Snow_Golem:

            this->type = std::pair<uint8_t, std::string>(type, "Snow Golem");
            this->isPassiveType = true;
        
        break;

        case EntityType::Ocelot:

            this->type = std::pair<uint8_t, std::string>(type, "Ocelot");
            this->isPassiveType = true;
        
        break;

        case EntityType::Horse:

            this->type = std::pair<uint8_t, std::string>(type, "Horse");
            this->isPassiveType = true;
        
        break;

        case EntityType::Donkey:

            this->type = std::pair<uint8_t, std::string>(type, "Donkey");
            this->isPassiveType = true;
        
        break;

        case EntityType::Mule:

            this->type = std::pair<uint8_t, std::string>(type, "Mule");
            this->isPassiveType = true;
        
        break;

        case EntityType::Skeleton_Horse:

            this->type = std::pair<uint8_t, std::string>(type, "Skeleton Horse");
            this->isPassiveType = true;
        
        break;

        case EntityType::Zombie_Horse:

            this->type = std::pair<uint8_t, std::string>(type, "Zombie Horse");
            this->isPassiveType = true;
        
        break;

        case EntityType::Polar_Bear:

            this->type = std::pair<uint8_t, std::string>(type, "Polar Bear");
            this->isPassiveType = true;
        
        break;

        case EntityType::Llama:

            this->type = std::pair<uint8_t, std::string>(type, "Llama");
            this->isPassiveType = true;
        
        break;

        case EntityType::Parrot:

            this->type = std::pair<uint8_t, std::string>(type, "Parrot");
            this->isPassiveType = true;
        
        break;

        case EntityType::Dolphin:

            this->type = std::pair<uint8_t, std::string>(type, "Dolphin");
            this->isPassiveType = true;
        
        break;

        case EntityType::Turtle:

            this->type = std::pair<uint8_t, std::string>(type, "Turtle");
            this->isPassiveType = true;
        
        break;

        case EntityType::Cat:

            this->type = std::pair<uint8_t, std::string>(type, "Cat");
            this->isPassiveType = true;
        
        break;

        case EntityType::Pufferfish:

            this->type = std::pair<uint8_t, std::string>(type, "Pufferfish");
            this->isPassiveType = true;
        
        break;

        case EntityType::Salmon:

            this->type = std::pair<uint8_t, std::string>(type, "Salmon");
            this->isPassiveType = true;
        
        break;

        case EntityType::Tropical_Fish:

            this->type = std::pair<uint8_t, std::string>(type, "Tropical Fish");
            this->isPassiveType = true;
        
        break;

        case EntityType::Cod:

            this->type = std::pair<uint8_t, std::string>(type, "Cod");
            this->isPassiveType = true;
        
        break;

        case EntityType::Panda:

            this->type = std::pair<uint8_t, std::string>(type, "Panda");
            this->isPassiveType = true;
        
        break;

        case EntityType::Villager_V2:

            this->type = std::pair<uint8_t, std::string>(type, "Villager");
            this->isPassiveType = true;
        
        break;

        case EntityType::Wandering_Trader:

            this->type = std::pair<uint8_t, std::string>(type, "Wandering Trader");
            this->isPassiveType = true;
        
        break;

        case EntityType::Fox:

            this->type = std::pair<uint8_t, std::string>(type, "Fox");
            this->isPassiveType = true;
        
        break;

        case EntityType::Bee:

            this->type = std::pair<uint8_t, std::string>(type, "Bee");
            this->isPassiveType = true;
        
        break;

        case EntityType::Strider:

            this->type = std::pair<uint8_t, std::string>(type, "Strider");
            this->isPassiveType = true;
        
        break;

        case EntityType::Goat:

            this->type = std::pair<uint8_t, std::string>(type, "Goat");
            this->isPassiveType = true;
        
        break;

        case EntityType::Frog:

            this->type = std::pair<uint8_t, std::string>(type, "Frog");
            this->isPassiveType = true;
        
        break;

        case EntityType::Tadpole:

            this->type = std::pair<uint8_t, std::string>(type, "Tadpole");
            this->isPassiveType = true;
        
        break;

        case EntityType::Allay:

            this->type = std::pair<uint8_t, std::string>(type, "Allay");
            this->isPassiveType = true;
        
        break;


        //

        
        case EntityType::Remote_Player:

            this->type = std::pair<uint8_t, std::string>(type, "Player");
        
        break;

        case EntityType::Shield:

            this->type = std::pair<uint8_t, std::string>(type, "Shield");
        
        break;


        //


        case EntityType::Elder_Guardian_Ghost:

            this->type = std::pair<uint8_t, std::string>(type, "Elder Guardian Ghost");
        
        break;


        //


        case EntityType::NPC:

            this->type = std::pair<uint8_t, std::string>(type, "NPC");
        
        break;

        case EntityType::Agent:

            this->type = std::pair<uint8_t, std::string>(type, "Agent");
        
        break;

        case EntityType::Tripod_Camera:

            this->type = std::pair<uint8_t, std::string>(type, "Tripod Camera");
        
        break;

        case EntityType::Chalkboard:

            this->type = std::pair<uint8_t, std::string>(type, "Chalkboard");
        
        break;


    };

};


//


auto _ActorData::getType(void) -> std::pair<uint8_t, std::string> {

    return this->type;

};


//


auto _ActorData::isHostile(void) -> bool {

    return this->isHostileType;

};

auto _ActorData::isPassive(void) -> bool {

    return this->isPassiveType;

};


//


auto _ActorData::isItem(void) -> bool {

    return this->isItemType;

};

auto _ActorData::isBlock(void) -> bool {

    return this->isBlocksType;

};

auto _ActorData::isImmobOrProj(void) -> bool {

    return this->isProjectileOrImmobileType;

};


//


auto Actor::getInfo(void) -> _ActorData* {

    return new _ActorData(this);

};


//


auto Actor::isValidMob(void) -> bool {

    auto info = this->getInfo();
    auto res = false;

    if(info->isHostile() || info->isPassive())
        res = true;
    
    if(info->getType().first == EntityType::Remote_Player)
        res = true;
    
    delete info;
    return res;

};

auto Actor::getType(void) -> std::pair<uint8_t, std::string> {
    
    auto info = this->getInfo();
    auto res = info->getType();

    delete info;
    return res;

};


//


auto Actor::getLevel(void) -> Level* {

    return *(Level**)((uintptr_t)(this) + 0x368);

};


//


auto Actor::onGround(void) -> bool* {

    return (bool*)((uintptr_t)(this) + 0x1D8);
    
};

auto Actor::getSize(void) -> Vec2<float> {

    return *(Vec2<float>*)((uintptr_t)(this) + 0x4D0);

};

auto Actor::getRuntimeId(void) -> uint64_t {

    return *(uint64_t*)((uintptr_t)(this) + 0x548);

};


//


auto Actor::setPos(Vec3<float> pos) -> void {

    using SetPos = void (__thiscall*)(Actor*, Vec3<float>*);
    auto _SetPos = (SetPos)(this->VTable[19]);

    _SetPos(this, &pos);

};

auto Actor::getPos(void) -> Vec3<float> {

    using GetPos = Vec3<float>* (__thiscall*)(Actor*);
    auto _GetPos = (GetPos)(this->VTable[22]);

    return *_GetPos(this);

};


//


auto Actor::getFiringPos(void) -> Vec3<float> {

    using GetFiringPos = Vec3<float> (__thiscall*)(Actor*);
    auto _GetFiringPos = (GetFiringPos)(this->VTable[26]);

    return _GetFiringPos(this);

};

auto Actor::setRot(Vec2<float> rot) -> void {

    using SetRot = void (__thiscall*)(Actor*, Vec2<float>*);
    auto _SetRot = (SetRot)(this->VTable[27]);

    return _SetRot(this, &rot);

};


//


auto Actor::isFireImmune(void) -> bool {

    using IsFireImmune = bool (__thiscall*)(Actor*);
    auto _IsFireImmune = (IsFireImmune)(this->VTable[39]);

    return _IsFireImmune(this);

};

auto Actor::canDisableShield(void) -> bool {

    using CanDisableShield = bool (__thiscall*)(Actor*);
    auto _CanDisableShield = (CanDisableShield)(this->VTable[42]);

    return _CanDisableShield(this);

};


//


auto Actor::teleportTo(Vec3<float> pos, bool p2, int p3, int p4, bool p5) -> void {

    using TeleportTo = void (__thiscall*)(Actor*, Vec3<float>*, bool, int, int, bool);
    auto _TeleportTo = (TeleportTo)(this->VTable[43]);

    return _TeleportTo(this, &pos, p2, p3, p4, p5);

};

auto Actor::tryTeleportTo(Vec3<float> pos, bool p2, bool p3, int p4, int p5) -> void {

    using TryTeleportTo = void (__thiscall*)(Actor*, Vec3<float>*, bool, bool, int, int);
    auto _TryTeleportTo = (TryTeleportTo)(this->VTable[44]);

    return _TryTeleportTo(this, &pos, p2, p3, p4, p5);

};

auto Actor::chorusFruitTeleport(Vec3<float> pos) -> void {

    using ChorusFruitTeleport = void (__thiscall*)(Actor*, Vec3<float>*);
    auto _ChorusFruitTeleport = (ChorusFruitTeleport)(this->VTable[45]);

    return _ChorusFruitTeleport(this, &pos);

};


//


auto Actor::lerpMotion(Vec3<float> motion) -> void {

    using LerpMotion = void (__thiscall*)(Actor*, Vec3<float>*);
    auto _LerpMotion = (LerpMotion)(this->VTable[46]);

    return _LerpMotion(this, &motion);

};


//


auto Actor::positionPassenger(Actor* entity, float p2) -> void {

    using PositionPassenger = void (__thiscall*)(Actor*, Actor*, float);
    auto _PositionPassenger = (PositionPassenger)(this->VTable[51]);

    return _PositionPassenger(this, entity, p2);

};

auto Actor::startRiding(Actor* entity) -> bool {

    using StartRiding = bool (__thiscall*)(Actor*, Actor*);
    auto _StartRiding = (StartRiding)(this->VTable[52]);

    return _StartRiding(this, entity);

};

auto Actor::addPassenger(Actor* entity) -> void {

    using AddPassenger = void (__thiscall*)(Actor*, Actor*);
    auto _AddPassenger = (AddPassenger)(this->VTable[53]);

    return _AddPassenger(this, entity);

};

auto Actor::flagPassengerToRemove(Actor* entity) -> void {

    using FlagPassengerToRemove = void (__thiscall*)(Actor*, Actor*);
    auto _FlagPassengerToRemove = (FlagPassengerToRemove)(this->VTable[54]);

    return _FlagPassengerToRemove(this, entity);

};


//


auto Actor::intersects(Vec3<float> p1, Vec3<float> p2) -> bool {

    using Intersects = bool (__thiscall*)(Actor*, Vec3<float>*, Vec2<float>*);
    auto _Intersects = (Intersects)(this->VTable[56]);

    return _Intersects(this, &p1, &p2);

};

auto Actor::isInWall(void) -> bool {

    using IsInWall = bool (__thiscall*)(Actor*);
    auto _IsInWall = (IsInWall)(this->VTable[57]);

    return _IsInWall(this);

};

auto Actor::isInvisible(void) -> bool {

    using IsInvisible = bool (__thiscall*)(Actor*);
    auto _IsInvisible = (IsInvisible)(this->VTable[58]);

    return _IsInvisible(this);

};


//


auto Actor::canShowNameTag(void) -> bool {

    using CanShowNameTag = bool (__thiscall*)(Actor*);
    auto _CanShowNameTag = (CanShowNameTag)(this->VTable[59]);

    return _CanShowNameTag(this);

};

auto Actor::setNameTagVisible(bool visible) -> void {

    using SetNameTagVisible = void (__thiscall*)(Actor*, bool);
    auto _SetNameTagVisible = (SetNameTagVisible)(this->VTable[61]);

    return _SetNameTagVisible(this, visible);

};

auto Actor::getNameTag(void) -> std::string {

    using GetNameTag = std::string* (__thiscall*)(Actor*);
    auto _GetNameTag = (GetNameTag)(this->VTable[62]);

    return *_GetNameTag(this);

};

auto Actor::setNameTag(std::string nametag) -> void {

    using SetNameTag = void (__thiscall*)(Actor*, std::string);
    auto _SetNameTag = (SetNameTag)(this->VTable[66]);

    return _SetNameTag(this, nametag);

};


//


auto Actor::isInWater(void) -> bool {

    using IsInWater = bool (__thiscall*)(Actor*);
    auto _IsInWater = (IsInWater)(this->VTable[70]);

    return _IsInWater(this);

};

auto Actor::hasEnteredWater(void) -> bool {

    using HasEnteredWater = bool (__thiscall*)(Actor*);
    auto _HasEnteredWater = (HasEnteredWater)(this->VTable[71]);

    return _HasEnteredWater(this);

};

auto Actor::isInLava(void) -> bool {

    using IsInLava = bool (__thiscall*)(Actor*);
    auto _IsInLava = (IsInLava)(this->VTable[72]);

    return _IsInLava(this);

};

auto Actor::isUnderLiquid(MaterialType type) -> bool {

    using IsUnderLiquid = bool (__thiscall*)(Actor*, MaterialType);
    auto _IsUnderLiquid = (IsUnderLiquid)(this->VTable[73]);

    return _IsUnderLiquid(this, type);

};

auto Actor::isOverWater(void) -> bool {

    using IsOverWater = bool (__thiscall*)(Actor*);
    auto _IsOverWater = (IsOverWater)(this->VTable[74]);

    return _IsOverWater(this);

};


//


auto Actor::setBlockMovementSlowdownMultiplier(BlockLegacy* legacy, Vec3<float> pos) -> void {

    using SetBlockMovementSlowdownMultiplier = void (__thiscall*)(Actor*, BlockLegacy*, Vec3<float>*);
    auto _SetBlockMovementSlowdownMultiplier = (SetBlockMovementSlowdownMultiplier)(this->VTable[75]);

    return _SetBlockMovementSlowdownMultiplier(this, legacy, &pos);

};

auto Actor::resetBlockMovementSlowdownMultiplier(void) -> void {

    using ResetBlockMovementSlowdownMultiplier = void (__thiscall*)(Actor*);
    auto _resetBlockMovementSlowdownMultiplier = (ResetBlockMovementSlowdownMultiplier)(this->VTable[76]);

    return _resetBlockMovementSlowdownMultiplier(this);
};


//


auto Actor::getHeadLookVector(float v) -> Vec3<float> {

    using GetHeadLookVector = Vec3<float> (__thiscall*)(Actor*, float);
    auto _GetHeadLookVector = (GetHeadLookVector)(this->VTable[80]);

    return _GetHeadLookVector(this, v);

};

auto Actor::canSee(Vec3<float> pos) -> bool {

    using CanSee = bool (__thiscall*)(Actor*, Vec3<float>*);
    auto _CanSee = (CanSee)(this->VTable[82]);

    return _CanSee(this, &pos);

};

auto Actor::canSee(Actor* entity) -> bool {

    using CanSee = bool (__thiscall*)(Actor*, Actor*);
    auto _CanSee = (CanSee)(this->VTable[83]);

    return _CanSee(this, entity);

};


//


auto Actor::isSkyLit(float f) -> bool {

    using IsSkyLit = bool (__thiscall*)(Actor*, float);
    auto _IsSkyLit = (IsSkyLit)(this->VTable[85]);

    return _IsSkyLit(this, f);

};

auto Actor::getBrightness(float f) -> float {

    using GetBrightness = float (__thiscall*)(Actor*, float);
    auto _GetBrightness = (GetBrightness)(this->VTable[86]);

    return _GetBrightness(this, f);

};


//


auto Actor::isImmobile(void) -> bool {

    using IsImmobile = bool (__thiscall*)(Actor*);
    auto _IsImmobile = (IsImmobile)(this->VTable[91]);

    return _IsImmobile(this);

};

auto Actor::isSilent(void) -> bool {

    using IsSilent = bool (__thiscall*)(Actor*);
    auto _IsSilent = (IsSilent)(this->VTable[92]);

    return _IsSilent(this);

};


//


auto Actor::isPickable(void) -> bool {

    using IsPickable = bool (__thiscall*)(Actor*);
    auto _IsPickable = (IsPickable)(this->VTable[94]);

    return _IsPickable(this);

};


//


auto Actor::isSleeping(void) -> bool {

    using IsSleeping = bool (__thiscall*)(Actor*);
    auto _IsSleeping = (IsSleeping)(this->VTable[96]);

    return _IsSleeping(this);

};

auto Actor::setSleeping(bool state) -> void {

    using SetSleeping = void (__thiscall*)(Actor*, bool);
    auto _SetSleeping = (SetSleeping)(this->VTable[97]);

    return _SetSleeping(this, state);

};


//


auto Actor::setSneaking(bool state) -> void {

    using SetSneaking = void (__thiscall*)(Actor*, bool);
    auto _SetSneaking = (SetSneaking)(this->VTable[99]);

    return _SetSneaking(this, state);

};

auto Actor::isBlocking(void) -> bool {

    using IsBlocking = bool (__thiscall*)(Actor*);
    auto _IsBlocking = (IsBlocking)(this->VTable[100]);

    return _IsBlocking(this);

};


//


auto Actor::isAlive(void) -> bool {

    using IsAlive = bool (__thiscall*)(Actor*);
    auto _IsAlive = (IsAlive)(this->VTable[102]);

    return _IsAlive(this);

};

auto Actor::isOnFire(void) -> bool {

    using IsOnFire = bool (__thiscall*)(Actor*);
    auto _IsOnFire = (IsOnFire)(this->VTable[103]);

    return _IsOnFire(this);

};

auto Actor::isOnHotBlock(void) -> bool {

    using IsOnHotBlock = bool (__thiscall*)(Actor*);
    auto _IsOnHotBlock = (IsOnHotBlock)(this->VTable[104]);

    return _IsOnHotBlock(this);

};


//


auto Actor::isSurfaceMob(void) -> bool {

    using IsSurfaceMob = bool (__thiscall*)(Actor*);
    auto _IsSurfaceMob = (IsSurfaceMob)(this->VTable[106]);

    return _IsSurfaceMob(this);

};


auto Actor::isRemotePlayer(void) -> bool {

    using IsRemotePlayer = bool (__thiscall*)(Actor*);
    auto _IsRemotePlayer = (IsRemotePlayer)(this->VTable[109]);

    return _IsRemotePlayer(this);

};


//


auto Actor::canAttack(Actor* entity, bool p2) -> bool {

    using CanAttack = bool (__thiscall*)(Actor*, Actor*, bool);
    auto _CanAttack = (CanAttack)(this->VTable[112]);

    return _CanAttack(this, entity, p2);

};


auto Actor::setTarget(Actor* entity) -> void {

    using SetTarget = void (__thiscall*)(Actor*, Actor*);
    auto _SetTarget = (SetTarget)(this->VTable[113]);

    return _SetTarget(this, entity);

};


//


auto Actor::getEquipmentCount(void) -> __int64 {

    using GetEquipmentCount = __int64 (__thiscall*)(Actor*);
    auto _GetEquipmentCount = (GetEquipmentCount)(this->VTable[117]);

    return _GetEquipmentCount(this);

};


//


auto Actor::setOwner(uint64_t runtimeId) -> void {

    using SetOwner = void (__thiscall*)(Actor*, uint64_t);
    auto _SetOwner = (SetOwner)(this->VTable[118]);

    return _SetOwner(this, runtimeId);

};


//


auto Actor::setSitting(bool state) -> void {

    using SetSitting = void (__thiscall*)(Actor*, bool);
    auto _SetSitting = (SetSitting)(this->VTable[119]);

    return _SetSitting(this, state);

};

auto Actor::setStanding(bool state) -> void {

    using SetStanding = void (__thiscall*)(Actor*, bool);
    auto _SetStanding = (SetStanding)(this->VTable[125]);

    return _SetStanding(this, state);

};


//


auto Actor::getInventorySize(void) -> __int64 {

    using GetInventorySize = __int64 (__thiscall*)(Actor*);
    auto _GetInventorySize = (GetInventorySize)(this->VTable[122]);

    return _GetInventorySize(this);

};

auto Actor::getEquipSlots(void) -> __int64 {

    using GetEquipSlots = __int64 (__thiscall*)(Actor*);
    auto _GetEquipSlots = (GetEquipSlots)(this->VTable[123]);

    return _GetEquipSlots(this);

};

auto Actor::getChestSlots(void) -> __int64 {

    using GetChestSlots = __int64 (__thiscall*)(Actor*);
    auto _GetChestSlots = (GetChestSlots)(this->VTable[124]);

    return _GetChestSlots(this);

};


//


auto Actor::canPowerJump(void) -> bool {

    using CanPowerJump = bool (__thiscall*)(Actor*);
    auto _CanPowerJump = (CanPowerJump)(this->VTable[126]);

    return _CanPowerJump(this);

};

auto Actor::setCanPowerJump(bool state) -> void {

    using SetCanPowerJump = void (__thiscall*)(Actor*, bool);
    auto _SetCanPowerJump = (SetCanPowerJump)(this->VTable[127]);

    return _SetCanPowerJump(this, state);

};

auto Actor::isJumping(void) -> bool {

    using IsJumping = bool (__thiscall*)(Actor*);
    auto _IsJumping = (IsJumping)(this->VTable[128]);

    return _IsJumping(this);

};


//


auto Actor::isInvulnerableTo(ActorDamageSource* actorDamageSource) -> bool {

    using IsInvulnerableTo = bool (__thiscall*)(Actor*, ActorDamageSource*);
    auto _IsInvulnerableTo = (IsInvulnerableTo)(this->VTable[134]);

    return _IsInvulnerableTo(this, actorDamageSource);

};

auto Actor::getBlockDamageCause(Block* block) -> ActorDamageCause {

    using GetBlockDamageCause = ActorDamageCause (__thiscall*)(Actor*, Block*);
    auto _GetBlockDamageCause = (GetBlockDamageCause)(this->VTable[135]);

    return _GetBlockDamageCause(this, block);

};


//


auto Actor::animateHurt(void) -> void {

    using AnimateHurt = void (__thiscall*)(Actor*);
    auto _AnimateHurt = (AnimateHurt)(this->VTable[136]);

    return _AnimateHurt(this);

};

auto Actor::doFireHurt(int v) -> void {

    using DoFireHurt = void (__thiscall*)(Actor*, int);
    auto _DoFireHurt = (DoFireHurt)(this->VTable[137]);

    return _DoFireHurt(this, v);

};


//


auto Actor::feed(int v) -> void {

    using Feed = void (__thiscall*)(Actor*, int);
    auto _Feed = (Feed)(this->VTable[140]);

};

auto Actor::getPickRadius(void) -> float {

    using GetPickRadius = float (__thiscall*)(Actor*);
    auto _GetPickRadius = (GetPickRadius)(this->VTable[142]);

    return _GetPickRadius(this);

};


//


auto Actor::setCarriedItem(ItemStack* itemStack) -> void {

    using SetCarriedItem = void (__thiscall*)(Actor*, ItemStack*);
    auto _SetCarriedItem = (SetCarriedItem)(this->VTable[160]);

    return _SetCarriedItem(this, itemStack);

};

auto Actor::getCarriedItem(void) -> ItemStack* {

    using GetCarriedItem = ItemStack* (__thiscall*)(Actor*);
    auto _GetCarriedItem = (GetCarriedItem)(this->VTable[161]);

    return _GetCarriedItem(this);

};


//


auto Actor::setOffhandSlot(ItemStack* itemStack) -> void {

    using SetOffhandSlot = void (__thiscall*)(Actor*, ItemStack*);
    auto _SetOffhandSlot = (SetOffhandSlot)(this->VTable[162]);

    return _SetOffhandSlot(this, itemStack);

};

auto Actor::getEquippedTotem(void) -> ItemStack* {

    using GetEquippedTotem = ItemStack* (__thiscall*)(Actor*);
    auto _GetEquippedTotem = (GetEquippedTotem)(this->VTable[163]);

    return _GetEquippedTotem(this);

};

auto Actor::consumeTotem(void) -> void {

    using ConsumeTotem = void (__thiscall*)(Actor*);
    auto _ConsumeTotem = (ConsumeTotem)(this->VTable[164]);

    return _ConsumeTotem(this);

};


//


auto Actor::getEntityTypeId(void) -> uint8_t {

    using GetEntityTypeId = uint8_t (__thiscall*)(Actor*);
    auto _GetEntityTypeId = (GetEntityTypeId)(this->VTable[169]);

    return _GetEntityTypeId(this);

};


//


auto Actor::checkFallDamage(float p1, bool p2) -> void {

    using CheckFallDamage = void (__thiscall*)(Actor*, float, bool);
    auto _CheckFallDamage = (CheckFallDamage)(this->VTable[184]);

    return _CheckFallDamage(this, p1, p2);

};

auto Actor::causeFallDamage(float p1,float p2, ActorDamageSource& actorDamageSource) -> void {

    using CheckFallDamage = void (__thiscall*)(Actor*, float, float, ActorDamageSource&);
    auto _CheckFallDamage = (CheckFallDamage)(this->VTable[185]);

    return _CheckFallDamage(this, p1, p2, actorDamageSource);

};

auto Actor::handleFallDistanceOnServer(float p1, float p2, bool p3) -> void {

    using HandleFallDistanceOnServer = void (__thiscall*)(Actor*, float, float, bool);
    auto _HandleFallDistanceOnServer = (HandleFallDistanceOnServer)(this->VTable[186]);

    return _HandleFallDistanceOnServer(this, p1, p2, p3);

};


//


auto Actor::canAddPassenger(Actor* entity) -> bool {

    using CanAddPassenger = bool (__thiscall*)(Actor*, Actor*);
    auto _CanAddPassenger = (CanAddPassenger)(this->VTable[191]);

    return _CanAddPassenger(this, entity);

};

auto Actor::inCaravan(void) -> bool {

    using InCaravan = bool (__thiscall*)(Actor*);
    auto _InCaravan = (InCaravan)(this->VTable[194]);

    return _InCaravan(this);

};


//


auto Actor::sendMotionPacketIfNeeded(void) -> void {

    using SendMotionPacketIfNeeded = void (__thiscall*)(Actor*);
    auto _SendMotionPacketIfNeeded = (SendMotionPacketIfNeeded)(this->VTable[197]);

    return _SendMotionPacketIfNeeded(this);

};


//


auto Actor::stopRiding(bool p1, bool p2, bool p3) -> void {

    using StopRiding = void (__thiscall*)(Actor*, bool, bool, bool);
    auto _StopRiding = (StopRiding)(this->VTable[199]);

    return _StopRiding(this, p1, p2, p3);

};


//


auto Actor::startSwimming(void) -> void {

    using StartSwimming = void (__thiscall*)(Actor*);
    auto _StartSwimming = (StartSwimming)(this->VTable[200]);

    return _StartSwimming(this);

};

auto Actor::stopSwimming(void) -> void {

    using StopSwimming = void (__thiscall*)(Actor*);
    auto _StopSwimming = (StopSwimming)(this->VTable[201]);

    return _StopSwimming(this);

};


//


auto Actor::isClientSide(void) -> bool {

    using IsClientSide = bool (__thiscall*)(Actor*);
    auto _IsClientSide = (IsClientSide)(this->VTable[204]);

    return _IsClientSide(this);

};


//


auto Actor::heal(int v) -> void {

    using Heal = void (__thiscall*)(Actor*, int);
    auto _Heal = (Heal)(this->VTable[208]);

    return _Heal(this, v);

};


//


auto Actor::isInvertedHealAndHarm(void) -> bool {

    using IsInvertedHealAndHarm = bool (__thiscall*)(Actor*);
    auto _IsInvertedHealAndHarm = (IsInvertedHealAndHarm)(this->VTable[209]);

    return _IsInvertedHealAndHarm(this);

};


//


auto Actor::openContainerComponent(Player* player) -> void {

    using OpenContainerComponent = void (__thiscall*)(Actor*, Player*);
    auto _OpenContainerComponent = (OpenContainerComponent)(this->VTable[217]);

    return _OpenContainerComponent(this, player);

};


//


auto Actor::swing(void) -> void {

    using Swing = void (__thiscall*)(Actor*);
    auto _Swing = (Swing)(this->VTable[218]);

    return _Swing(this);

};


//


auto Actor::useItem(ItemStackBase* itemStackBase, ItemUseMethod itemUseMethod, bool p3) -> void {

    using UseItem = void (__thiscall*)(Actor*, ItemStackBase*, ItemUseMethod, bool);
    auto _UseItem = (UseItem)(this->VTable[219]);

    return _UseItem(this, itemStackBase, itemUseMethod, p3);

};


//


auto Actor::isWorldBuilder(void) -> bool {
    
    using IsWorldBuilder = bool (__thiscall*)(Actor*);
    auto _IsWorldBuilder = (IsWorldBuilder)(this->VTable[228]);

    return _IsWorldBuilder(this);

};

auto Actor::isInCreative(void) -> bool {
    
    using IsInCreative = bool (__thiscall*)(Actor*);
    auto _IsInCreative = (IsInCreative)(this->VTable[229]);

    return _IsInCreative(this);

};

auto Actor::isAdventure(void) -> bool {
    
    using IsAdventure = bool (__thiscall*)(Actor*);
    auto _IsAdventure = (IsAdventure)(this->VTable[230]);

    return _IsAdventure(this);

};

auto Actor::isSurvival(void) -> bool {
    
    using IsSurvival = bool (__thiscall*)(Actor*);
    auto _IsSurvival = (IsSurvival)(this->VTable[231]);

    return _IsSurvival(this);

};

auto Actor::isSpectator(void) -> bool {
    
    using IsSpectator = bool (__thiscall*)(Actor*);
    auto _IsSpectator = (IsSpectator)(this->VTable[232]);

    return _IsSpectator(this);

};

auto Actor::isAttackableGamemode(void) -> bool {
    
    using IsAttackableGamemode = bool (__thiscall*)(Actor*);
    auto _IsAttackableGamemode = (IsAttackableGamemode)(this->VTable[233]);

    return _IsAttackableGamemode(this);

};


//


auto Actor::setSize(float width, float height) -> void {

    using SetSize = void (__thiscall*)(Actor*, float, float);
    auto _SetSize = (SetSize)(this->VTable[239]);

    return _SetSize(this, width, height);

};