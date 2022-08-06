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


auto MCRenderer::getTextWidth(std::string text, float fontSize) -> float {

    auto ctx = MCRenderer::getContext();
    auto font = MCRenderer::getFont();

    if(ctx == nullptr || font == nullptr)
        return 0.f;
    
    return ctx->getLineLength(font, &text, fontSize, false);

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

auto MCRenderer::flushText(void) -> void {

    auto ctx = MCRenderer::getContext();

    if(ctx == nullptr)
        return;
    
    return ctx->flushText(0.f);

};


//


auto MCRenderer::fillRectangle(Vec4<float> rectPos, Color rectColor) -> void {

    auto ctx = MCRenderer::getContext();

    if(ctx == nullptr)
        return;
    
    ctx->fillRectangle(Vec4<float>(rectPos.x, rectPos.z, rectPos.y, rectPos.w), rectColor, rectColor.w * 255.f);

};

auto MCRenderer::drawRectangle(Vec4<float> rectPos, Color rectColor, int rectLineWidth) -> void {

    auto ctx = MCRenderer::getContext();

    if(ctx == nullptr)
        return;
    
    ctx->drawRectangle(Vec4<float>(rectPos.x, rectPos.z, rectPos.y, rectPos.w), rectColor, rectColor.w * 255.f, rectLineWidth);

};