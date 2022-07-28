#include "Actor.h"

auto Actor::getLevel(void) -> Level* {

    return *(Level**)((uintptr_t)(this) + 0x368);

};


//


auto Actor::onGround(void) -> bool* {

    return (bool*)((uintptr_t)(this) + 0x1D8);
    
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


auto Actor::getEntityTypeId(void) -> uint8_t {

    using GetEntityTypeId = uint8_t (__thiscall*)(Actor*);
    auto _GetEntityTypeId = (GetEntityTypeId)(this->VTable[169]);

    return _GetEntityTypeId(this);

};