#include "Entity.h"

#include "../../../Manager.h"

Manager* ehMgr = nullptr;

typedef void (__thiscall* EntityTick)(Actor*, void*, void*);
EntityTick _EntityTick;

auto EntityTick_Callback(Actor* entity, void* p2, void* p3) -> void {


    ehMgr->entityMap[entity->getRuntimeId()] = entity;
    
    _EntityTick(entity, p2, p3);

};

auto Entity_Hook::init(void) -> void {

    ehMgr = this->manager;

    auto sig = Utils::findSig("0F B6 81 ? ? ? ? C3 ? ? ? ? ? ? ? ? 48 8B 91 ? ? ? ? 0F");

    if(!sig)
        return Utils::debugLog("[ Entity Tick Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &EntityTick_Callback, reinterpret_cast<LPVOID*>(&_EntityTick)) != MH_OK)
        return Utils::debugLog("[ Entity Tick Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ Entity Tick Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};