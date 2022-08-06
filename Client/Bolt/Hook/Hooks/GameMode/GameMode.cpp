#include "GameMode.h"

#include "../../../Category/Category.h"
#include "../../../Manager.h"

Manager* gmMgr = nullptr;

typedef void (__thiscall* GameModeTick)(GameMode*);
GameModeTick _GameModeTick;

auto GameModeTick_Callback(GameMode* GM) -> void {

    gmMgr->cleanEntityMap();

    for(auto [ type, category ] : gmMgr->categories) {

        for(auto mod : category->modules) {

            if(mod->isEnabled)
                mod->onGameMode(GM);

        };

    };

    _GameModeTick(GM);

};

auto GameMode_Hook::init(void) -> void {

    gmMgr = this->manager;

    auto sig = Utils::findSig("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 0A 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B");

    if(!sig)
        return Utils::debugLog("[ ClientInstance Hook ] Failed to find Signature needed for Hook!");
    
    int offset = *reinterpret_cast<int*>(sig + 3);
    uintptr_t** VTable = reinterpret_cast<uintptr_t**>(sig + offset + 7);
    
    if(MH_CreateHook((void*)VTable[8], &GameModeTick_Callback, reinterpret_cast<LPVOID*>(&_GameModeTick)) != MH_OK)
        return Utils::debugLog("[ GameMode::tick Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ GameMode::tick Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)VTable[8]);

};