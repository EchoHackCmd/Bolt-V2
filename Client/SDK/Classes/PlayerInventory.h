#ifndef CLIENT_SDK_CLASSES_PLAYERINVENTORY
#define CLIENT_SDK_CLASSES_PLAYERINVENTORY

#include "../../Utils/Utils.h"

class ItemStack;
class ItemInstance;

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
private:
    virtual auto getTagRegistry(void) -> void*;
public:
    virtual auto getItemInstance(int) -> ItemInstance*;
private:
    virtual auto Function9(void) -> void;
    virtual auto Function10(void) -> void;
public:
    virtual auto setItem(int, ItemStack*) -> void;
};

#endif /* CLIENT_SDK_CLASSES_PLAYERINVENTORY */