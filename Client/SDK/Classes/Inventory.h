#ifndef CLIENT_SDK_CLASSES_INVENTORY
#define CLIENT_SDK_CLASSES_INVENTORY

#include "../../Utils/Utils.h"

struct ContainerContentChangeListener;
class ItemStack;
class BlockSource;
class Item;
class Player;
class ItemInstance;
struct CompoundTag;
struct ListTag;

class Inventory {
private:
    virtual ~Inventory(void);
public:
    virtual auto init(void) -> void;
    virtual auto serverInitItemStackIds(int, int, class std::function<void (int, class ItemStack const &)>) -> void;
    virtual auto addContentChangeListener(ContainerContentChangeListener*) -> void;
    virtual auto removeContentChangeListener(ContainerContentChangeListener*) -> void;
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
    virtual auto startOpen(class Player*) -> void;
    virtual auto stopOpen(class Player*) -> void;
    virtual auto getSlotCopies(void) -> std::vector<ItemStack>;
    virtual auto getSlots(void) -> std::vector<ItemStack*>;
    virtual auto getItemCount(ItemStack*) -> int;
    virtual auto findFirstSlotForItem(ItemStack*) -> int;
    virtual auto canPushInItem(BlockSource &, int32_t, int32_t, ItemInstance const&) -> bool;
    virtual auto canPullOutItem(BlockSource &,int32_t,int32_t,ItemInstance const&) -> bool;
    virtual auto setContainerChanged(int) -> void;
    virtual auto setContainerMoved(void) -> void;
    virtual auto setCustomName(std::string) -> void;
    virtual auto hasCustomName(void) -> bool;
    virtual auto readAdditionalSaveData(CompoundTag const&) -> void;
    virtual auto addAdditionalSaveData(CompoundTag&) -> void;
    virtual auto createTransactionContext(std::function<void (Inventory &, int, ItemStack const &, ItemStack const &)>,std::function<void (void)>) -> void;
    virtual auto initializeContainerContents(BlockSource &) -> void;
    virtual auto isEmpty(void) -> bool;
    virtual auto add(ItemStack*) -> bool;
    virtual auto canAdd(ItemStack*) -> bool;
    virtual auto clearSlot(int) -> void;
    virtual auto clearInventory(int) -> void;
    virtual auto load(ListTag const&, void* const&, Level &) -> void;
    virtual auto getEmptySlotsCount(void) -> __int64;
    virtual auto getFirstEmptySlot(void) -> __int64;
    virtual auto setContainerSize(int) -> void;
};

#endif /* CLIENT_SDK_CLASSES_INVENTORY */
