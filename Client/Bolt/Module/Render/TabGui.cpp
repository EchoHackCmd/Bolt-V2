#include "TabGui.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto TabGui::onRender(void) -> void {

    this->updateAlpha();

    auto instance = Minecraft::getClientInstance();
    auto guidata = (instance != nullptr ? instance->getGuiData() : nullptr);

    if(guidata == nullptr)
        return;

    auto fontSize = (guidata->uiScale > 1 ? 8.6f * guidata->uiScale : 15 * guidata->uiScale);
    auto textColor = ImColor(75.f, 219.f, 113.f, this->alpha);
    auto bgColor = ImColor(28.f, 28.f, 28.f, (this->alpha - .6f));
    
    auto mgr = this->category->manager;
    auto categories = mgr->categories;

    {

        auto currRect = ImVec4(10.f, 10.f, 10.f, 10.f + (categories.size() * fontSize));

        for(auto [ type, category ] : categories) {

            auto name = category->getName();
            auto size = RenderUtils::getTextSize(name, fontSize);

            if(currRect.z < size.x)
                currRect.z = size.x;
            
            if(type == (categories.size() - 1))
                currRect.x += currRect.x;

        };

        RenderUtils::fillRect(nullptr, currRect, bgColor, 3.f);
        
        for(auto [ type, category ] : categories) {

            auto name = category->getName();
            auto size = RenderUtils::getTextSize(name, fontSize);
            
            RenderUtils::drawText(nullptr, ImVec2(currRect.x, (currRect.y + size.y) + ((int)type * fontSize)), name, fontSize, textColor);

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