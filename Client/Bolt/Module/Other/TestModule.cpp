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

    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr)
        return;
    
    //

};

auto TestModule::onPacket(Packet* packet, bool* cancel) -> void {

    //onPacket event - Handled by LoopbackPacketSender::send Hook

    if(packet->getId() == PacketType::MovePlayer) {

        Utils::debugLog("!");

    };

};

auto TestModule::onKey(uint64_t key, bool isDown, bool* cancel) -> void {

    //onKey event - Handled by WINAPI Key Hook

};

bool hook = false;

typedef void (__thiscall* Draw) (MinecraftUIRenderContext*, Font*, Rect*, std::string*, Color*, float, TextAlignment*, TextMeasureData*, CaretMeasureData*);
Draw _Draw;

bool once = false;

auto Draw_Callback(MinecraftUIRenderContext* _this, Font* font, Rect* rect, std::string* text, Color* color, float textSize, TextAlignment* textAlignment, TextMeasureData* textMeasureData, CaretMeasureData* caretMeasureData) -> void {

    //

    _Draw(_this, font, rect, text, color, textSize, textAlignment, textMeasureData, caretMeasureData);

};

auto TestModule::onRenderCtx(MinecraftUIRenderContext* ctx) -> void {

    MCRenderer::drawText("Hello World!", Vec2<float>(50.f, 50.f), Color(255.f, 255.f, 255.f), 2.f);

};