#include "TestModule.h"

#include "../../Category/Category.h"

#include "../../Manager.h"
#include "../../../Client.h"

auto TestModule::onTick(void) -> void {

    //

};

auto TestModule::onEnable(void) -> void {

    Utils::debugLog("Enabled: " + this->name);

};

auto TestModule::onDisable(void) -> void {

    Utils::debugLog("Disabled: " + this->name);
    
    this->category->manager->isRunning = false;

};

auto TestModule::onRender(void) -> void {

    //

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    auto mgr = this->category->manager;
    auto entities = mgr->entityMap;
    auto player = GM->player;

    if(player == nullptr || entities.empty())
        return;

    auto distances = std::vector<double>();
    auto myPos = player->getPos();

    for(auto [ runtimeId, entity] : entities) {

        if(runtimeId == player->getRuntimeId() || !entity->isAlive())
            continue;
        
        auto dist = entity->getPos().distanceTo(myPos);

        if(dist <= 12.f)
            distances.push_back(dist);

    };

    std::sort(distances.begin(), distances.end());

    if(distances.empty())
        return;

    for(auto [ runtimeId, entity] : entities) {

        if(runtimeId == player->getRuntimeId() || !entity->isAlive())
            continue;
        
        auto dist = entity->getPos().distanceTo(myPos);

        if(dist == distances.at(0) || (distances.size() > 1 ? dist == distances.at(1) : distances.at(0)))
            GM->attack(entity);

    };

};