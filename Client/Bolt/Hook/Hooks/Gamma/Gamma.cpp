#include "Gamma.h"

#include "../../../Manager.h"

Manager* ehMgr = nullptr;

typedef float(__stdcall* C_Gamma)(uintptr_t*);
C_Gamma _Gamma;

float gammaCallback(uintptr_t* a1) {
	_Gamma(a1);
}

auto Gamma_Hook::init(void) -> void {

    ehMgr = this->manager;

    auto sig = Utils::findSig("48 83 EC ? 80 B9 ? ? ? ? ? 48 8D 54 24 ? 48 8B 01 74 ? 41 B8 ? ? ? ? FF 50 ? 48 8B 10 48 85 D2 74 ? 48 8B 42 ? 48 8B 88 ? ? ? ? 48 85 C9 74 ? E8 ? ? ? ? 48 83 C4 ? C3 F3 0F 10 42 ? 48 83 C4 ? C3 41 B8 ? ? ? ? FF 50 ? 48 8B 10 48 85 D2 75 ? E8 ? ? ? ? CC E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC ? 48 8B 01");

    if(!sig)
        return Utils::debugLog("[ Gamma Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &gammaCallback, reinterpret_cast<LPVOID*>(&_Gamma)) != MH_OK)
        return Utils::debugLog("[ Gamma Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ Gamma Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};