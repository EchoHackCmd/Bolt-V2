#include "ClientInstance.h"

auto ClientInstance::getLocalPlayer(void) -> uintptr_t* {

    using GetLocalPlayer = uintptr_t* (__thiscall*)(ClientInstance*);
    auto _GetLocalPlayer = (GetLocalPlayer)(this->VTable[24]);

    return _GetLocalPlayer(this);

};

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