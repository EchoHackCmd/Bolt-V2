#include "TestModule.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"


/* Events handled by DLL - Not by hooks */

auto TestModule::onTick(void) -> void {

    //onTick event - Handled by DLL

    /*

        Do not use this for calling VTable methods of the game process! Crash may occur!!
    
    */

};

auto TestModule::onEnable(void) -> void {

    //onEnable event - Handled by DLL

};

auto TestModule::onDisable(void) -> void {

    this->category->manager->isRunning = false;

};


/* Events handled by hooks */


auto TestModule::onRender(void) -> void {

    //onRender event - Handled by SwapChain Hook

};

auto TestModule::onGamma(float* gamma) -> void {

    //onGamma event - Handled by Gamma Hook

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    //onGameMode event - Handled by GameMode::tick Hook

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr)
        return;
    
    //

};

auto TestModule::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    //onKey event - Handled by WINAPI Key Hook

};