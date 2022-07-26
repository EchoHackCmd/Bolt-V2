#include "RenderUtils.h"

SwapChain_DeviceType RenderUtils::deviceType = SwapChain_DeviceType::INVALID_DEVICE_TYPE;

auto RenderUtils::drawText(ImDrawList* draw, ImVec2 textPos, std::string text, float fontSize = 1.f, ImColor color = ImColor(255.f, 255.f, 255.f)) -> void {
    
    if(draw == nullptr)
        draw = ImGui::GetBackgroundDrawList();
    
    draw->AddText(ImGui::GetFont(), fontSize, textPos, ImColor(color.Value.x / 255.f, color.Value.y / 255.f, color.Value.z / 255.f, color.Value.w), text.c_str());

};

auto RenderUtils::getTextSize(std::string text, float fontSize) -> ImVec2 {
    
    auto font = ImGui::GetFont();
    return font->CalcTextSizeA(fontSize, 1000.f, -1.f, text.c_str());

};

auto RenderUtils::fillRect(ImDrawList* draw, ImVec4 rectPos, ImColor color, float round = 0.f) -> void {
    
    if(draw == nullptr)
        draw = ImGui::GetBackgroundDrawList();
    
    draw->AddRectFilled(ImVec2(rectPos.x, rectPos.y), ImVec2(rectPos.z, rectPos.w), ImColor(color.Value.x / 255.f, color.Value.y / 255.f, color.Value.z / 255.f, color.Value.w), round);

};

auto RenderUtils::drawRect(ImDrawList* draw, ImVec4 rectPos, ImColor color, float round = 0.f, float thickness = 1.f) -> void {
    
    if(draw == nullptr)
        draw = ImGui::GetBackgroundDrawList();
    
    draw->AddRect(ImVec2(rectPos.x, rectPos.y), ImVec2(rectPos.z, rectPos.w), ImColor(color.Value.x / 255.f, color.Value.y / 255.f, color.Value.z / 255.f, color.Value.w), round, 0, thickness);

};