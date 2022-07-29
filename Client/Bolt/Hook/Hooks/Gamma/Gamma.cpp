#include "Gamma.h"

#include "../../../Category/Category.h"
#include "../../../Manager.h"

Manager* ghMgr = nullptr;

typedef float (__thiscall* Gamma)(uintptr_t*);
Gamma _Gamma;

auto gammaCallback(uintptr_t* p1) -> float {

    auto res = 0.f;

    for(auto [ type, category ] : ghMgr->categories) {

        for(auto mod : category->modules) {

            if(mod->isEnabled)
                mod->onGamma(&res);

        };

    };
	
    return (res > 0.f ? res : _Gamma(p1));

};

auto Gamma_Hook::init(void) -> void {

    ghMgr = this->manager;

    auto sig = Utils::findSig("48 83 EC ? 80 B9 ? ? ? ? ? 48 8D 54 24 ? 48 8B 01 74 ? 41 B8 ? ? ? ? FF 50 ? 48 8B 10 48 85 D2 74 ? 48 8B 42 ? 48 8B 88 ? ? ? ? 48 85 C9 74 ? E8 ? ? ? ? 48 83 C4 ? C3 F3 0F 10 42 ? 48 83 C4 ? C3 41 B8 ? ? ? ? FF 50 ? 48 8B 10 48 85 D2 75 ? E8 ? ? ? ? CC E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC ? 48 8B 01");

    if(!sig)
        return Utils::debugLog("[ Gamma Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &gammaCallback, reinterpret_cast<LPVOID*>(&_Gamma)) != MH_OK)
        return Utils::debugLog("[ Gamma Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ Gamma Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};