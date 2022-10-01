#include "Packet.h"

#include "../../../Category/Category.h"
#include "../../../Manager.h"

Manager* phMgr = nullptr;

typedef void (__thiscall* Send) (LoopbackPacketSender* _this, Packet*);
Send _Send;

auto PacketSend_Callback(LoopbackPacketSender* _this, Packet* packet) -> void {

    bool cancel = false;
    
    for(auto [ type, category ] : phMgr->categories) {

        for(auto mod : category->modules) {

            if(mod->isEnabled)
                mod->onPacket(packet, &cancel);

        };

    };

    if(!cancel)
        _Send(_this, packet);

};

auto Packet_Hook::init(void) -> void {

    phMgr = this->manager;

    auto sig = Utils::findSig("48 89 5C 24 ? 57 48 83 EC ? 48 8B ? 48 8B ? 48 8B 49 ? ? ? ? ? ? ? ? ? 48 8B");

    if(!sig)
        return Utils::debugLog("[ LoopbackPacketSender::send Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &PacketSend_Callback, reinterpret_cast<LPVOID*>(&_Send)) != MH_OK)
        return Utils::debugLog("[ LoopbackPacketSender::send Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ LoopbackPacketSender::send Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};