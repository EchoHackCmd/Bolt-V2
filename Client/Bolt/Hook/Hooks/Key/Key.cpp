#include "Key.h"

#include "../../../Category/Category.h"
#include "../../../Manager.h"

Manager* khMgr = nullptr;

typedef void (__thiscall* Key) (uint64_t, bool);
Key _Key;

auto KeyHook_Callback(uint64_t key, bool isDown) -> void {

    auto cancel = false;
    khMgr->keyMap[key] = isDown;

    auto instance = Minecraft::getClientInstance();
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    for(auto [ type, category] : khMgr->categories) {

        for(auto mod : category->modules) {

            if(isDown && mcGame != nullptr && mcGame->canUseKeys())
                if(mod->key == key)
                    mod->isEnabled = !mod->isEnabled;
            
            if(mod->isEnabled)
                mod->onKey(key, isDown, &cancel);

        };

    };

    if(!cancel)
        _Key(key, isDown);

};

auto Key_Hook::init(void) -> void {

    khMgr = this->manager;
    
    auto sig = Utils::findSig("48 ? ? 48 ? ? ? 4C 8D 05 ? ? ? ? 89");

    if(!sig)
        return Utils::debugLog("[ Key Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &KeyHook_Callback, reinterpret_cast<LPVOID*>(&_Key)) != MH_OK)
        return Utils::debugLog("[ Key Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ Key Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};