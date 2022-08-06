#include "Uninject.h"

#include "../../Manager.h"
#include "../../../Client.h"
#include "../../Category/Category.h"

auto Uninject::onEnable(void) -> void {

    this->category->manager->isRunning = false;

};