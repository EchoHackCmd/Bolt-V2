#include "Minecraft.h"

ClientInstance* Minecraft::clientInstance = nullptr;

auto Minecraft::setClientInstance(ClientInstance* i) -> void {

    if(i == nullptr)
        return;
    
    clientInstance = i;

};

auto Minecraft::getClientInstance(void) -> ClientInstance* {

    return clientInstance;

};