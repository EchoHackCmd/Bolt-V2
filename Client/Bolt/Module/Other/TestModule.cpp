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

    //onDisable event - Handled by DLL

};


/* Events handled by hooks */


auto TestModule::onRender(void) -> void {
auto textColor = ImColor(255.f, 255.f, 255.f, 1.f);
auto otherclr = ImColor(170.f, 170.f, 170.f, 1.0f);
	std::string build = "Build - ";
#ifdef _DEBUG
	std::string buildType = "Developer";
#else
	std::string buildType = "Public";
#endif

//build info yes its shitty code but w/e
		RenderUtils::drawText(nullptr, ImVec2(1705, 975), build, 30.f, otherclr);
		RenderUtils::drawText(nullptr, ImVec2(1780, 975), buildType, 30.f, textColor);
};

auto TestModule::onGamma(float* gamma) -> void {

    //onGamma event - Handled by Gamma Hook

};

auto TestModule::onGameMode(GameMode* GM) -> void {

    //onGameMode event - Handled by GameMode::tick Hook

};

auto TestModule::onPacket(Packet* packet, bool* cancel) -> void {

    //onPacket event - Handled by LoopbackPacketSender::send Hook

};

auto TestModule::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    //onKey event - Handled by WINAPI Key Hook

};

auto TestModule::onRenderCtx(MinecraftUIRenderContext* ctx) -> void {


};