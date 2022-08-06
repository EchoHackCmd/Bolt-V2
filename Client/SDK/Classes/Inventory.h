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
private:
    virtual auto Function21(void) -> void;
    virtual auto Function22(void) -> void;
public:
    virtual auto setContainerChanged(int) -> void;
    virtual auto setContainerMoved(void) -> void;
public:
    virtual auto setCustomName(std::string) -> void;
public:
    virtual auto isWatchingIfActorEnters(void) -> bool;
private:
    virtual auto Function27(void) -> void;
    virtual auto Function28(void) -> void;
public:
    virtual auto createTransactionContext(std::function<void (Inventory &, int, ItemStack const &, ItemStack const &)>,std::function<void (void)>) -> void;
private:
    virtual auto Function30(void) -> void;
public:
    virtual auto isEmpty(void) -> bool;
    virtual auto add(ItemStack*) -> bool;
    virtual auto canAdd(ItemStack*) -> bool;
    virtual auto clearSlot(int) -> void;
    virtual auto clearInventory(int) -> void;
private:
    virtual auto Function36(void) -> void;
public:
    virtual auto getEmptySlotsCount(void) -> __int64;
    virtual auto getFirstEmptySlot(void) -> __int64;
    virtual auto setContainerSize(int) -> void;
};

#endif /* CLIENT_SDK_CLASSES_INVENTORY */