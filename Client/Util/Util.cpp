#include "Util.h"

auto Util::getDll(void) -> HMODULE {

    MEMORY_BASIC_INFORMATION info;
    size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)getDll, &info, sizeof(info));
    assert(len == sizeof(info));
    return len ? (HMODULE)info.AllocationBase : NULL;

};

auto Util::getDebugDir(void) -> std::string {

    char* path = NULL;
    size_t length;

    _dupenv_s(&path, &length, "appdata");

    return std::string(path);

};

auto Util::debugLog(std::string output) -> void {

    static bool init = false;
    static auto path = std::string(getDebugDir() + "\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState");

    auto file = std::string(path + "\\Output.txt");

    if(!init) {
        auto f = std::filesystem::path(file);

        if(std::filesystem::exists(f))
            std::filesystem::remove(f);
        
        init = true;
    };
    
    CloseHandle(CreateFileA(file.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

    std::ofstream fStream;
    fStream.open(file.c_str(), std::ios::app);
    
    if(fStream.is_open())
        fStream << output << "\n" << std::endl;
    
    return fStream.close();

};