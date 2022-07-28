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

};

auto TestModule::onRender(void) -> void {

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(mcGame == nullptr || !mcGame->canUseKeys())
        return;
    
    auto mgr = this->category->manager;
    auto entities = mgr->entityMap;

    if(entities.empty())
        return;
    
    RenderUtils::drawText(nullptr, ImVec2(10.f, 10.f), "Entities: [ " + std::to_string(entities.size()) + " ]", 20.f, ImColor(255.f, 255.f, 255.f));

};