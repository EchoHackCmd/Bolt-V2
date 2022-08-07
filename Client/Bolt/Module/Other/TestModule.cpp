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

    //onRender event - Handled by SwapChain Hook

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

    auto instance = ctx->clientInstance;
    auto guidata = (instance != nullptr ? instance->getGuiData() : nullptr);

    if(guidata == nullptr)
        return;

    auto screen = guidata->screenRes3;
    
    auto text = std::string("Bolt V2");
    auto fontSize = 1.f;

    auto calcWidth = MCRenderer::getTextWidth(text, fontSize);
    auto rectPos = Vec4<float>(10.f, screen.y - 26.f, 14.f + calcWidth, screen.y - 12.f);

    auto textColor = Color(42.f, 199.f, 123.f);
    auto bgColor = Color(21.f, 21.f, 21.f, 0.6f);
    
    MCRenderer::drawText(text, Vec2<float>(rectPos.x + 2.f, rectPos.y + 2.f), textColor, fontSize);
    MCRenderer::drawRectangle(rectPos, textColor, 2);
    MCRenderer::fillRectangle(rectPos, bgColor);

    MCRenderer::flushText();

};