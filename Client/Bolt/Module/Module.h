#ifndef CLIENT_BOLT_MODULE_MODULE
#define CLIENT_BOLT_MODULE_MODULE

#include "../../Utils/Utils.h"

class Category;
class GameMode;

class Module {
public:
    std::string name;
    Category* category;
public:
    uint64_t key;
    bool isEnabled = false, wasEnabled = false;
public:
    std::map<uintptr_t, std::vector<BYTE>> patches;
public:
    Module(std::string, Category*);
public:
    auto setState(bool) -> void;
    auto setKey(uint64_t) -> void;
public:
    virtual auto onTick(void) -> void {};
    virtual auto onEnable(void) -> void {};
    virtual auto onDisable(void) -> void {};
public:
    virtual auto onRender(void) -> void {};
    virtual auto onGameMode(GameMode*) -> void {};
    virtual auto onKey(uint64_t, bool, bool*) -> void {};
public:
    virtual auto onGamma(float*) -> void {};
public:
    auto getBytes(void* src, unsigned int bytes) -> std::vector<BYTE> {

        auto res = std::vector<BYTE>();

        for(auto I = 0; I < bytes; I++) {

            res.push_back(*(BYTE*)((uintptr_t)(src) + I));

        };

        return res;

    };

    auto nopBytes(void* src, unsigned int bytes) -> void {

        DWORD oldprotect;
        VirtualProtect(src, bytes, PAGE_EXECUTE_READWRITE, &oldprotect);
        
        memset(src, 0x90, bytes);

        VirtualProtect(src, bytes, oldprotect, &oldprotect);

    };

    auto patchBytes(void* src, std::vector<BYTE> bytes) -> void {

        DWORD oldprotect;
        
        VirtualProtect(src, bytes.size(), PAGE_EXECUTE_READWRITE, &oldprotect);

        for(auto I = 0; I < bytes.size(); I++) {

            *(BYTE*)((uintptr_t)(src) + I) = bytes.at(I);

        };
        
        VirtualProtect(src, bytes.size(), oldprotect, &oldprotect);

    };
};

#endif /* CLIENT_BOLT_MODULE_MODULE */