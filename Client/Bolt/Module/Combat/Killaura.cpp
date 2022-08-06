#include "Killaura.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Killaura::onGameMode(GameMode* GM) -> void {

    auto player = GM->player;
    
    auto mgr = this->category->manager;
    auto entityMap = mgr->entityMap;

    auto distances = std::vector<float>();
    
    for(auto [ runtimeId, entity ] : entityMap) {

        auto info = _ActorData(entity);

        if(player->getRuntimeId() == runtimeId || (info.isItem() || info.isBlock() || info.isImmobOrProj()))
            continue;
        
        if(!entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = player->getPos().distanceTo(entity->getPos());
        
        if(dist <= this->range)
            distances.push_back(dist);

    };

    if(distances.empty())
        return;
    
    std::sort(distances.begin(), distances.end());
    auto I = 0;

    for(auto [ runtimeId, entity ] : entityMap) {

        if(I >= 2)
            break;

        auto info = _ActorData(entity);

        if(player->getRuntimeId() == runtimeId || (info.isItem() || info.isBlock() || info.isImmobOrProj()))
            continue;
        
        if(!entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = player->getPos().distanceTo(entity->getPos());
        
        if(dist == distances.at(0) || dist == (distances.size() > 1 ? distances.at(1) : distances.at(0))) {

            GM->attack(entity);
            player->swing();
            I++;

        };

    };

};