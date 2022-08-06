#include "Packet.h"

auto Packet::getId(void) -> enum PacketType {
    using GetId = PacketType (__thiscall*)(Packet*);
    auto _GetId = (GetId)(this->VTable[1]);

    return _GetId(this);
};

auto Packet::getName(void) -> std::string {
    using GetName = std::string* (__thiscall*)(Packet*);
    auto _GetName = (GetName)((*(uintptr_t**)(this))[2]);

    return _GetName(this)->c_str();
};