#include "AutoWeapon.h"
#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto AutoWeapon::onGameMode(GameMode* GM) -> void {
    auto player = GM->player;
    for (int i = 0; i < 9; i++) {
        int itemSlot = player->getSupplies()->selectedHotbarSlot();
        ItemStack* stack = player->getSupplies()->inventory->getItem(i);
        //if (stack->item != nullptr) {
          //  if (stack->getItem(i)->isSword() && itemSlot != i)
                player->getSupplies()->selectedHotbarSlot(i) = i;
      //  }
    }
}
      //note to whoever we dont have what we need but the code is done