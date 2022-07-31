#include "TabGui.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto TabGui::onRender(void) -> void {

    this->updateAlpha();

    auto textColor = ImColor(34.f, 201.f, 126.f, this->alpha);
    auto bgColor = ImColor(28.f, 28.f, 28.f, (this->alpha - .6f));
    
    auto mgr = this->category->manager;
    auto categories = mgr->categories;

    auto instance = Minecraft::getClientInstance();
    auto guidata = (instance != nullptr ? instance->getGuiData() : nullptr);

    if(guidata == nullptr)
        return;

    { /* Categories */

        auto currWidth = 0.f;
        auto start = ImVec2(10.f, 10.f);
        auto fontSize = guidata->uiScale * 12.f;

        for(auto [ type, category ] : categories) {

            auto name = category->getName();
            auto textSize = RenderUtils::getTextSize(name, fontSize);
            
            if(textSize.x > currWidth)
                currWidth = textSize.x;
            
            RenderUtils::drawText(nullptr, ImVec2(start.x + 4.f, start.y + ((int)type + textSize.y)), name, fontSize, textColor);

        };

    };

};

auto TabGui::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    //

};

auto TabGui::updateAlpha(void) -> void {

    auto reachOff = [&](float* value, float target, float modifier) {
        if(*value < target)
            *value += modifier;
        else
            *value -= modifier;
    };

    auto instance = Minecraft::getClientInstance();
    
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);
    
    auto modifier = 0.04f;
    
    if(mcGame == nullptr || player == nullptr)
        return reachOff(&alpha, 1.f, modifier);
    
    if(mcGame->canUseKeys())
        return reachOff(&alpha, 1.f, modifier);
    else
        return reachOff(&alpha, .0f, modifier);
    
};