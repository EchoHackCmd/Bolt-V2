#include "Step.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Step::onGameMode(GameMode* GM) -> void {

    *Game.getClientInstance()->getLocalPlayer()->getStepHeight() = 2.5625f;
};

auto Step::onDisable(void) -> void {
    if(Game.getClientInstance()->getLocalPlayer() == nullptr) return; 
//looks cleaner idk just me? ok then.
    *Game.getClientInstance()->getLocalPlayer()->getStepHeight() = 0.5625f;
};