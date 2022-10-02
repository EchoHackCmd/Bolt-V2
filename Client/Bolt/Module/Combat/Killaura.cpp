#include "Killaura.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Killaura::onGameMode(GameMode* GM) -> void {

    if(std::chrono::system_clock::now() < (this->time + std::chrono::milliseconds(this->msDelay)))
        return;

    this->time = std::chrono::system_clock::now();
    this->cpt = 0;

    auto mgr = this->category->manager;
    auto entityMap = mgr->entityMap;
    
    auto player = GM->player;
    auto myPos = *player->getPos();

    if(entityMap.size() <= 1)
        return;
    
    auto dists = std::vector<float>();

    for(auto [ runtimeId, entity ] : entityMap) {

        if(!entity->isValidMob() || entity->isInvisible())
            continue;
        
        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = (*entity->getPos()).distanceTo(myPos);
        
        if(dist <= this->range)
            dists.push_back(dist);

    };

    if(dists.empty())
        return;
    
    std::sort(dists.begin(), dists.end());

    auto hits = 0;
    for(auto [ runtimeId, entity ] : entityMap) {

        if(hits > this->cpt)
            break;

        if(!entity->isValidMob() || entity->isInvisible())
            continue;

        if(player->getRuntimeId() == runtimeId || !entity->isAlive() || !player->canAttack(entity, false))
            continue;
        
        auto dist = (*entity->getPos()).distanceTo(myPos);
        
        if(dist == dists.at(0)) {

            dists.erase(dists.begin());
            GM->attack(entity);
            player->swing();
            hits++;

        };

    };

};