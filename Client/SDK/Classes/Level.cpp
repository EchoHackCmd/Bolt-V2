#include "Level.h"

auto Level::getRuntimeEntity(uint64_t actorUniqueId, bool p2) -> Actor* {

    using GetRuntimeEntity = Actor* (__thiscall*)(Level*, uint64_t, bool);
    auto _GetRuntimeEntity = (GetRuntimeEntity)(this->VTable[49]);

    return _GetRuntimeEntity(this, actorUniqueId, p2);

};

auto Level::getPrimaryLocalPlayer(void) -> Player* {

    using GetPrimaryLocalPlayer = Player* (__thiscall*)(Level*);
    auto _GetPrimaryLocalPlayer = (GetPrimaryLocalPlayer)(this->VTable[60]);

    return _GetPrimaryLocalPlayer(this);

};