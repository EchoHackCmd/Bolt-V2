#ifndef CLIENT_SDK_CLASSES_INVENTORY
#define CLIENT_SDK_CLASSES_INVENTORY

#include "../../Utils/Utils.h"

struct ContainerContentChangeListener;
class ItemStack;
class BlockSource;

class Inventory {
private:
    virtual ~Inventory(void);
public:
    virtual auto init(void) -> void;
    virtual auto serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>) -> void;
    virtual auto addContentChangeListener(ContainerContentChangeListener*) -> void;
    virtual auto removeContentChangeListener(ContainerContentChangeListener*) -> void;
public:
    virtual auto getItem(int) -> ItemStack*;
    virtual auto hasRoomForItem(ItemStack*) -> bool;
    virtual auto addItem(ItemStack*) -> bool;
    virtual auto addItemToFirstEmptySlot(ItemStack*) -> bool;
    virtual auto setItem(int, ItemStack*) -> void;
    virtual auto setItemWithForceBalance(int, ItemStack*, bool) -> void;
    virtual auto removeItem(int, int) -> void;
    virtual auto removeAllItems(void) -> void;
    virtual auto dropContents(BlockSource*, Vec3<float>, bool) -> void;
    virtual auto getContainerSize(void) -> __int64;
    virtual auto getMaxStackSize(void) -> __int64;
private:
    virtual auto Function15(void) -> void;
    virtual auto Function16(void) -> void;
public:
    virtual auto getSlotCopies(void) -> std::vector<ItemStack>;
    virtual auto getSlots(void) -> std::vector<ItemStack*>;
public:
    virtual auto getItemCount(ItemStack*) -> int;
    virtual auto findFirstSlotForItem(ItemStack*) -> int;
};

#endif /* CLIENT_SDK_CLASSES_INVENTORY */