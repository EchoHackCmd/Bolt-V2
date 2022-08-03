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
    auto bgColor = ImColor(21.f, 21.f, 21.f, (this->alpha - .4f));
    
    auto mgr = this->category->manager;
    auto categories = mgr->categories;

    auto currRect = ImVec2(0.f, 0.f);
    
    for(auto [ type, category ] : categories) {

        auto calcSize = RenderUtils::getTextSize(category->getName(), fontSize);

        if(calcSize.x > currRect.x)
            currRect.x = calcSize.x;
        
        if((int)type == (categories.size() - 1))
            currRect.y = (categories.size() * fontSize) + 14.f;

    };

    RenderUtils::fillRect(nullptr, ImVec4(10.f, 10.f, 14.f + currRect.x, currRect.y), bgColor, 3.f);

    for(auto [ type, category ] : categories) {

        RenderUtils::drawText(nullptr, ImVec2(12.f, 12.f + ((int)(type) * fontSize)), category->getName(), fontSize, textColor);

    };

    if(sCategory) {

        if(iCatXOff <= 0.f)
            iCatXOff = 11.f;

        reachOff(&iCatXOff, 13.f + currRect.x, (float)guidata->uiScale);

        auto category = categories[(CategoryType)iCategory];
        auto calcSize = RenderUtils::getTextSize(category->getName(), fontSize);

        auto yOff = calcSize.y + (iCategory * fontSize);
        RenderUtils::fillRect(nullptr, ImVec4(11.f, 12.f + yOff, iCatXOff, 13.f + yOff), textColor, 3.f);

    };

};

auto TabGui::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    if(!isDown)
        return;
    
    if(key != VK_LEFT && key != VK_RIGHT && key != VK_UP && key != VK_DOWN)
        return;
    
    auto instance = Minecraft::getClientInstance();
    
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);

    if(mcGame == nullptr || (player != nullptr && !mcGame->canUseKeys()))
        return;
    
    auto manager = this->category->manager;
    auto categories = manager->categories;

    auto category = categories[(CategoryType)iCategory];
    auto modules = (category != nullptr ? category->modules : std::vector<Module*>());

    if(key == VK_RIGHT) {

        if(!sCategory) {

            sCategory = true;

        } else {

            if(!sModule) {

                sModule = true;

            } else {

                if(modules.empty())
                    return;
                
                auto currModule = modules.at(iModule);

                if(currModule != nullptr)
                    currModule->isEnabled = !currModule->isEnabled;

            };

        };

    } else if(key == VK_LEFT) {

        if(sModule && sCategory) {

            sModule = false;
            iModXOff = 0.f;

        } else if(sCategory) {

            sCategory = false;
            iCatXOff = 0.f;

        };

    } else if(key == VK_DOWN) {

        if(sCategory && !sModule) {

            iCategory++;
            iCatXOff = 0.f;

            if(iCategory >= categories.size())
                iCategory = 0;

        };

    } else if(key == VK_UP) {

        if(sCategory && !sModule) {

            if(iCategory <= 0)
                iCategory = categories.size();
            
            iCategory--;
            iCatXOff = 0.f;

        };

    };

    *cancel = true;

};

auto TabGui::updateAlpha(void) -> void {

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

auto TabGui::reachOff(float* value, float target, float modifier) -> void {
    if(*value < target + modifier) {
        if(*value < target)
            *value += modifier;
    } else if(*value > target - modifier) {
        if(*value > target)
            *value -= modifier;
    };
};