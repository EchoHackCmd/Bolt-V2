#include "Entity.h"

#include "../../../Manager.h"

Manager* ehMgr = nullptr;

typedef void (__thiscall* EntityTick)(Actor*, void*);
EntityTick _EntityTick;

auto EntityTick_Callback(Actor* entity, void* p2) -> void {

    ehMgr->cleanEntityMap();
    ehMgr->entityMap[entity->getRuntimeId()] = entity;
    
    _EntityTick(entity, p2);

};

auto Entity_Hook::init(void) -> void {

    ehMgr = this->manager;

    auto sig = Utils::findSig("48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC 60 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 4C 8B E2 48 8B"); /* Minecraft Functions suck */

    if(!sig)
        return Utils::debugLog("[ Entity Tick Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &EntityTick_Callback, reinterpret_cast<LPVOID*>(&_EntityTick)) != MH_OK)
        return Utils::debugLog("[ Entity Tick Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ Entity Tick Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};