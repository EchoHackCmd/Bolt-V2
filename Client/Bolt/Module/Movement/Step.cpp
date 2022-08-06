#include "Step.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Step::onGameMode(GameMode* GM) -> void {
    auto player = GM->player;
    auto mgr = this->category->manager;

    player->stepHeight = 2.0f; //until we have settings
};

auto Step::onDisable(void) -> void {
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    player->stepHeight = 0.5625f; 
};
