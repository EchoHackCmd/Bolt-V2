#include "NoPacket.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto NoPacket::onPacket(Packet* packet, bool* cancelSend) -> void {
 cancelSend = true;
};
