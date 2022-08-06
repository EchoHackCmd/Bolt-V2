#ifndef CLIENT_UTILS_RENDERUTILS
#define CLIENT_UTILS_RENDERUTILS

#include <filesystem>
#include <functional>
#include <Windows.h>
#include <MinHook.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <Psapi.h>
#include <cassert>
#include <vector>
#include <map>

#include <dxgi.h>
#include <d3d11.h>
#include <d3d12.h>
#include <d2d1_1.h>
#include <dxgi1_4.h>
#include <dwrite_1.h>
#include <initguid.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dwrite.lib")

#include "../../Includes/imgui/imgui_impl_win32.h"
#include "../../Includes/imgui/imgui_impl_dx12.h"
#include "../../Includes/imgui/imgui_impl_dx11.h"
#include "../../Includes/imgui/imgui.h"

#include "../../Includes/kiero/kiero.h"

enum SwapChain_DeviceType { INVALID_DEVICE_TYPE, D3D11, D3D12 };

class RenderUtils {
public:
    static SwapChain_DeviceType deviceType;
public:
    static auto drawText(ImDrawList*, ImVec2, std::string, float, ImColor) -> void;
    static auto getTextSize(std::string, float) -> ImVec2;
public:
    static auto fillRect(ImDrawList*, ImVec4, ImColor, float) -> void;
    static auto drawRect(ImDrawList*, ImVec4, ImColor, float, float) -> void;
};

#endif /* CLIENT_UTILS_RENDERUTILS */