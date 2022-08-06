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
    virtual auto onGameMode(class GameMode*) -> void {};
    virtual auto onKey(uint64_t, bool, bool*) -> void {};
    virtual auto onPacket(class Packet*, bool*) -> void {};
    virtual auto onRenderCtx(class MinecraftUIRenderContext*) -> void {};
public:
    virtual auto onGamma(float*) -> void {};
public:
    auto getBytes(void*, unsigned int) -> std::vector<BYTE>;
    auto patchBytes(void*, std::vector<BYTE>) -> void;
    auto nopBytes(void*, unsigned int) -> void;
};

#endif /* CLIENT_BOLT_MODULE_MODULE */