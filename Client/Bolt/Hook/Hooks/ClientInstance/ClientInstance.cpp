#include "ClientInstance.h"

#include "../../../Category/Category.h"
#include "../../../Manager.h"

Manager* ciMgr = nullptr;

typedef void ( __thiscall* RenderContext ) ( void*, MinecraftUIRenderContext* );
RenderContext _RenderContext;

auto RenderContext_Callback( void* a1, MinecraftUIRenderContext* ctx ) -> void {

    Minecraft::setClientInstance(ctx->clientInstance);
    MCRenderer::setContext(ctx);

    for(auto [ type, category ] : ciMgr->categories) {

        for(auto mod : category->modules) {

            if(mod->isEnabled)
                mod->onRenderCtx(ctx);

        };

    };
    
    _RenderContext(a1, ctx);

};

auto ClientInstance_Hook::init(void) -> void {

    ciMgr = this->manager;

    auto sig = Utils::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA");

    if(!sig)
        return Utils::debugLog("[ ClientInstance Hook ] Failed to find Signature needed for Hook!");
    
    if(MH_CreateHook((void*)sig, &RenderContext_Callback, reinterpret_cast<LPVOID*>(&_RenderContext)) != MH_OK)
        return Utils::debugLog("[ ClientInstance Hook ] Failed to create Hook!");
    
    Utils::debugLog("[ ClientInstance Hook ] Initialized Hook, enabling Hook!");
    MH_EnableHook((void*)sig);

};