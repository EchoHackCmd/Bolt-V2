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

    auto catRect = ImVec4(10.f, 10.f, 14.f + currRect.x, currRect.y);
    RenderUtils::fillRect(nullptr, catRect, bgColor, 3.f);

    for(auto [ type, category ] : categories) {

        RenderUtils::drawText(nullptr, ImVec2(12.f, 12.f + ((int)(type) * fontSize)), category->getName(), fontSize, textColor);

    };

    if(sCategory) {

        if(iCatXOff <= 0.f)
            iCatXOff = catRect.x + 1.f;

        reachOff(&iCatXOff, catRect.z - 2.f, (float)guidata->uiScale);

        auto category = categories[(CategoryType)iCategory];
        auto calcSize = RenderUtils::getTextSize(category->getName(), fontSize);

        auto yOff = calcSize.y + (catRect.y + (iCategory * fontSize));
        RenderUtils::fillRect(nullptr, ImVec4(catRect.x + 2.f, yOff + 1.f, iCatXOff, yOff + 2.f), textColor, 3.f);


        /* Display Modules in current Category */

        
        auto modules = (category != nullptr ? category->modules : std::vector<Module*>());
        currRect = ImVec2(0.f, 0.f);

        if(modules.empty())
            return;
        
        auto I = 0;
        for(auto mod : modules) {

            auto calcSize = RenderUtils::getTextSize(mod->name, fontSize);

            if(calcSize.x > currRect.x)
                currRect.x = calcSize.x;
            
            if(I == (modules.size() - 1))
                currRect.y = (modules.size() * fontSize) + 14.f;
            
            I++;

        };
        
        auto modsRect = ImVec4(catRect.z + 2.f, catRect.y + (iCategory * fontSize), (catRect.z + 2.f) + (12.f + currRect.x), (catRect.y + (iCategory * fontSize)) + (modules.size() * fontSize) + 4.f);
        RenderUtils::fillRect(nullptr, modsRect, bgColor, 3.f);

        I = 0;
        for(auto mod : modules) {

            auto displayColor = (mod->isEnabled ? textColor : ImColor(209.f, 78.f, 54.f, this->alpha));

            if(sModule && iModule == I) {

                if(iModXOff <= 0.f)
                    iModXOff = modsRect.x + 1.f;

                reachOff(&iModXOff, modsRect.z - 2.f, (float)guidata->uiScale);

                auto calcSize = RenderUtils::getTextSize(mod->name, fontSize);

                auto yOff = calcSize.y + (modsRect.y + (iModule * fontSize));
                RenderUtils::fillRect(nullptr, ImVec4(modsRect.x + 2.f, yOff + 1.f, iModXOff, yOff + 2.f), displayColor, 3.f);

            };

            RenderUtils::drawText(nullptr, ImVec2(modsRect.x + 4.f, modsRect.y + (I * fontSize) + 2.f), mod->name, fontSize, displayColor);
            I++;

        };

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

        } else if(sModule) {

            iModule++;
            iModXOff = 0.f;

            if(iModule >= modules.size())
                iModule = 0;

        };

    } else if(key == VK_UP) {

        if(sCategory && !sModule) {

            if(iCategory <= 0)
                iCategory = categories.size();
            
            iCategory--;
            iCatXOff = 0.f;

        } else if(sModule) {

            if(iModule <= 0)
                iModule = modules.size();
            
            iModule--;
            iModXOff = 0.f;

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