#include "MinecraftUIRenderContext.h"
#include "ClientInstance.h"

MinecraftUIRenderContext* MCRenderer::ctx = nullptr;

auto MCRenderer::setContext(MinecraftUIRenderContext* ctxPtr) -> void {

    MCRenderer::ctx = ctxPtr;

};

auto MCRenderer::getContext(void) -> MinecraftUIRenderContext* {

    return MCRenderer::ctx;

};


//


auto MCRenderer::getFont(void) -> Font* {

    if(MCRenderer::ctx == nullptr)
        return nullptr;
    
    auto instance = MCRenderer::ctx->clientInstance;
    auto mcGame = (instance != nullptr ? instance->getMinecraftGame() : nullptr);
    
    auto font = (mcGame != nullptr ? mcGame->mcFont() : nullptr);
    return (font != nullptr ? font : nullptr);

};


//


auto MCRenderer::drawText(std::string text, Vec2<float> textPos, Color color, float fontSize) -> void {

    auto ctx = MCRenderer::getContext();
    auto font = MCRenderer::getFont();

    if(ctx == nullptr || font == nullptr)
        return;
    
    TextMeasureData textMeasureData = TextMeasureData(fontSize);
    CaretMeasureData caretMeasureData = CaretMeasureData();

    Rect rect = Rect(textPos.x, textPos.x + (textPos.x * fontSize), textPos.y, textPos.y + (textPos.y * fontSize / 2));
    ctx->drawText(font, &rect, &text, &color, color.w * 255.f, nullptr, &textMeasureData, &caretMeasureData);

};