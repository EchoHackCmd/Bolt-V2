#include "Step.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Step::onGameMode(GameMode* GM) -> void {
    
    auto player = GM->player;
    *player->getStepHeight() = 2.5625f;

};

auto Step::onDisable(void) -> void {
    
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr)
        return;
    
    *player->getStepHeight() = 0.5625f;
};