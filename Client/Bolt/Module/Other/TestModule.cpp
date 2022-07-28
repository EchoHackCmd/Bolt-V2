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

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(mcGame == nullptr || !mcGame->canUseKeys())
        return;
    
    auto mgr = this->category->manager;
    auto entities = mgr->entityMap;

    if(entities.empty())
        return;
    
    auto stringA = std::string("Entities: [ " + std::to_string(entities.size()) + " ]");
    auto stringB = player->getNameTag();

    auto fontSize = 25.f;


    auto scaleA = RenderUtils::getTextSize(stringA, fontSize);
    auto scaleB = RenderUtils::getTextSize(stringB, fontSize);

    RenderUtils::fillRect(nullptr, ImVec4(10.f, 10.f, 10.f + scaleA.x, 10.f + scaleA.y), ImColor(21.f, 21.f, 21.f, .8f), 5.f);
    RenderUtils::drawText(nullptr, ImVec2(10.f, 10.f), stringA, fontSize, ImColor(255.f, 255.f, 255.f));
    
    RenderUtils::fillRect(nullptr, ImVec4(10.f, (11.f + scaleA.y), 10.f + scaleB.x, (11.f + scaleA.y) + scaleB.y), ImColor(21.f, 21.f, 21.f, .8f), 5.f);
    RenderUtils::drawText(nullptr, ImVec2(10.f, (11.f + scaleA.y)), stringB, fontSize, ImColor(255.f, 255.f, 255.f));

    auto currItem = player->getCarriedItem();
    
    std::ostringstream o;
    o << std::hex << currItem;

    Utils::debugLog(o.str());
    return this->setState(false);
};