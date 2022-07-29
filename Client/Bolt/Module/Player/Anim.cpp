#include "Anim.h"

#include "../../Category/Category.h"

#include "../../../Client.h"
#include "../../Manager.h"

auto Anim::onTick(void) -> void {
 
 auto instance = Minecraft::getClientInstance();

   auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    
    if (LOOPAnim) {
        
        bool OnceAnim = false;
        
        if (Hurtanim) {
            
            player->animateHurt();
        };
    
    };
    
};



auto Anim::onEnable(void) -> void {
    
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    
    if (Hurtanim) {

        player->animateHurt();

    };
  
};

auto Anim::onDisable(void) -> void {
    
    this->category->manager->isRunning = false;

};