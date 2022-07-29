#include "Anim.h"

#include "../../Category/Category.h"

#include "../../../Client.h"
#include "../../Manager.h"

auto Anim::onGameMode(GameMode* GM) -> void {
    
    auto player = GM->player;

    if(player == nullptr)
        return this->setState(false);
    
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