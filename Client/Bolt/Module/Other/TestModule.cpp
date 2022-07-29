#include "TestModule.h"

#include "../../Category/Category.h"

#include "../../Manager.h"
#include "../../../Client.h"

auto TestModule::onGamma(float* f) -> void {

    *f = 100.f;

};