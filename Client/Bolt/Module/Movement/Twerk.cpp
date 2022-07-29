#include "Twerk.h"

#include "../../Category/Category.h"

#include "../../Manager.h"
#include "../../../Client.h"

auto Twerk::onTick(void) -> void {
 
 auto instance = Minecraft::getClientInstance();

   auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
       auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);


    //
  
player->setSneaking(true);
player->setSneaking(false);
};

auto Twerk::onEnable(void) -> void {

    Utils::debugLog("Enabled: " + this->name);

};

auto Twerk::onDisable(void) -> void {

    Utils::debugLog("Disabled: " + this->name);
    
    this->category->manager->isRunning = false;

};

auto Twerk::onRender(void) -> void {


};

auto Twerk::onGameMode(GameMode* GM) -> void {
 
  
 
};