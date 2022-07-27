#include "Actor.h"

auto Actor::onGround(void) -> bool* {

    return (bool*)((uintptr_t)(this) + 0x1D8);
    
};

auto Actor::setPos(Vec3<float> pos) -> void {

    using SetPos = void (__thiscall*)(Actor*, Vec3<float>*);
    auto _SetPos = (SetPos)(this->VTable[19]);

    _SetPos(this, &pos);

};