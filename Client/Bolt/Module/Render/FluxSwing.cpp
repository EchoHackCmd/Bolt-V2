#include "FluxSwing.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

void* fluxSwingAddr = (void*)(Utils::findSig("e8 ? ? ? ? 41 0f 28 c0 f3 41 0f 5c c1"));
char ogFlux[5] = {};

auto FluxSwing::onEnable(void) -> void {
	if (fluxSwingAddr == nullptr)
		return;
	
	Utils::copyBytes(fluxSwingAddr, ogFlux, 5);
	Utils::nopBytes(fluxSwingAddr, 5);	
	
};

auto FluxSwing::onDisable(void) -> void{
	
	Utils::patchBytes(fluxSwingAddr, ogFlux, 5);

};