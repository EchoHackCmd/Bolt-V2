#include "TestModule.h"

#include "../../Category/Category.h"
#include "../../Manager.h"

auto TestModule::onTick(void) -> void {

    //

};

auto TestModule::onEnable(void) -> void {

    Utils::debugLog("Enabled: " + this->name);

};

auto TestModule::onDisable(void) -> void {

    Utils::debugLog("Disabled: " + this->name);

};

ClientInstance* instance = nullptr;

auto TestModule::onRender(void) -> void {

    RenderUtils::drawText(nullptr, ImVec2(10.f, 10.f), "Hello, World!", 20.f, ImColor(255.f, 255.f, 255.f));

    if(instance == nullptr) {

        instance = Minecraft::getClientInstance();

        if(instance != nullptr) {

            std::ostringstream o;
            o << std::hex << instance;

            Utils::debugLog("ClientInstance: " + o.str());

        };

    };

};