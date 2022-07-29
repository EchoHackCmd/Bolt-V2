#include "Anim.h"

#include "../../Category/Category.h"

#include "../../Manager.h"
#include "../../../Client.h"

auto Anim::onTick(void) -> void {
 
 auto instance = Minecraft::getClientInstance();

   auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
if (LOOPAnim) {
    bool OnceAnim = false;
    if (Hurtanim) {
player->animateHurt();
    }
   
    }
    //
}



auto Anim::onEnable(void) -> void {
 auto instance = Minecraft::getClientInstance();

   auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    Utils::debugLog("Enabled: " + this->name);
 if (Hurtanim) {
player->animateHurt();
    }
  
};

auto Anim::onDisable(void) -> void {

    Utils::debugLog("Disabled: " + this->name);
    
    this->category->manager->isRunning = false;

};

