#include "ClientInstance.h"

auto ClientInstance::getMinecraftGame(void) -> MinecraftGame* {

    return *(MinecraftGame**)((uintptr_t)(this) + 0xA8);

};

auto ClientInstance::getGuiData(void) -> GuiData* {

    return *(GuiData**)((uintptr_t)(this) + 0x500);

};


//


auto ClientInstance::getLocalPlayer(void) -> Player* {

    using GetLocalPlayer = Player* (__thiscall*)(ClientInstance*);
    auto _GetLocalPlayer = (GetLocalPlayer)(this->VTable[24]);

    return _GetLocalPlayer(this);

};


//


auto ClientInstance::grabMouse(void) -> void {
    
    using GrabMouse = void (__thiscall*)(ClientInstance*);
    auto _GrabMouse = (GrabMouse)(this->VTable[289]);

    _GrabMouse(this);

};

auto ClientInstance::releaseMouse(void) -> void {
    
    using ReleaseMouse = void (__thiscall*)(ClientInstance*);
    auto _ReleaseMouse = (ReleaseMouse)(this->VTable[290]);

    _ReleaseMouse(this);

};