#include "SwapChain.h"

Manager* mgr = nullptr;

auto SwapChain_Hook::init(void) -> void {

    mgr = this->manager;
    //

};