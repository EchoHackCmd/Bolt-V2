#include "TestModule.h"

auto TestModule::onTick(void) -> void {

    Util::debugLog("Tick: " + this->name);

};