#include "Killaura.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Killaura::onGameMode(GameMode* GM) -> void {

    auto mgr = this->category->manager;
    auto entityMap = mgr->entityMap;
    
    auto player = GM->player;
    auto myPos = *player->getPos();

    if(entityMap.size() <= 1)
        return;
    
    auto dists = std::vector<float>();

    for(auto [ runtimeId, entity ] : entityMap) {

        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = (*entity->getPos()).distanceTo(myPos);
        
        if(dist <= this->range)
            dists.push_back(dist);

    };

    if(dists.empty())
        return;
    
    std::sort(dists.begin(), dists.end());

    for(auto [ runtimeId, entity ] : entityMap) {

        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = (*entity->getPos()).distanceTo(myPos);
        
        if(dist == dists.at(0) || dist == (dists.size() > 1 ? dists.at(1) : dists.at(0))) {

            GM->attack(entity);
            player->swing();
            break;

        };

    };

};