#ifndef CLIENT_SDK_CLASSES_PLAYERINVENTORY
#define CLIENT_SDK_CLASSES_PLAYERINVENTORY

#include "Inventory.h"

class PlayerInventory {
public:
    inline Inventory* getInventory() {
        
        return *reinterpret_cast<Inventory**>((uintptr_t)(this) + 0xC0);

    };

    inline int32_t getSelectedSlot() {
        
        return *reinterpret_cast<int32_t*>((uintptr_t)(this) + 0x10);

    };

    inline void setSelectedSlot(int32_t slot) {
        
        *reinterpret_cast<int32_t*>((uintptr_t)(this) + 0x10) = slot;

    };
};

#endif /* CLIENT_SDK_CLASSES_PLAYERINVENTORY */