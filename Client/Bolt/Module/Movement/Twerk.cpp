#include "Twerk.h"

#include "../../Category/Category.h"

#include "../../Manager.h"
#include "../../../Client.h"

auto Twerk::onGameMode(GameMode* GM) -> void {
    
    auto player = GM->player;
    
    if(player == nullptr)
        return this->setState(false);
    
    player->setSneaking(true);
    player->setSneaking(false);

};