#ifndef CLIENT_SDK_CLASSES_PLAYERINVENTORY
#define CLIENT_SDK_CLASSES_PLAYERINVENTORY

#include "../../Utils/Utils.h"

class ItemStack;

class PlayerInventory {
private:
    virtual ~PlayerInventory();
private:
    virtual auto Function0(void) -> void;
public:
    virtual auto releaseResources(void) -> void;
    virtual auto getContainerSize(void) -> __int64;
    virtual auto getFilteredContainerSize(void) -> __int64;
private:
    virtual auto Function4(void) -> void;
    virtual auto getContainerWeakRef(void) -> void*;
public:
    virtual auto getItemStack(int) -> ItemStack*;
};

#endif /* CLIENT_SDK_CLASSES_PLAYERINVENTORY */