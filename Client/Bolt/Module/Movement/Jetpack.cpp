#include "Jetpack.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Jetpack::onTick(void) -> void {

    auto mgr = this->category->manager;
    
    if(!mgr->isUsingKey(this->key))
        return this->setState(false);
    
    auto instance = Minecraft::getClientInstance();
    auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);

    if(player == nullptr || !player->isAlive())
        return this->setState(false);

};

auto Jetpack::onGameMode(GameMode* GM) -> void {

    auto player = GM->player;
    auto bodyRot = *player->getRot();

    auto angles = Vec2<float>((bodyRot.x) * -(3.14 / 180.f), (bodyRot.y + 90.f) * 3.14 / 180.f);
    auto motion = Vec3<float>(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed);

    player->lerpMotion(&motion);

};