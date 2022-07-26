#include "Hitbox.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Hitbox::onGameMode(GameMode* GM) -> void {

    auto player = GM->player;
    auto mgr = this->category->manager;

    for(auto [ runtimeId, entity ] : mgr->entityMap) {

        if(!entity->isValidMob())
            continue;

        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto type = entity->getEntityTypeId();

        if(!this->sizes.contains(type))
            this->sizes[type] = *entity->getSize();
        
        entity->setSize(this->size.x, this->size.y);

    };

};

auto Hitbox::onDisable(void) -> void {

    auto mgr = this->category->manager;
    
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr)
        return this->sizes.clear();
    
    for(auto [ runtimeId, entity] : mgr->entityMap) {

        if(!entity->isValidMob())
            continue;
        
        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto type = entity->getEntityTypeId();
        auto currSize = (this->sizes.contains(type) ? this->sizes[type] : Vec2<float>(0.f, 0.f));
        
        if(currSize.x <= 0.f || currSize.y <= 0.f)
            continue;
        
        entity->setSize(currSize.x, currSize.y);

    };

};