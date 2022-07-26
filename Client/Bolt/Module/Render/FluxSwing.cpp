#include "FluxSwing.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto FluxSwing::onEnable(void) -> void {

	if(patches.empty()) {

		auto fluxSwingAddr = Utils::findSig("e8 ? ? ? ? f3 44 0f 59 35 ? ? ? ? f3 0f 10 15");
		auto bytes = getBytes((void*)fluxSwingAddr, 5);

		patches[fluxSwingAddr] = bytes;

	};

	for(auto [ addr, bytes ] : patches) {

		nopBytes((void*)addr, bytes.size());

	};

};

auto FluxSwing::onDisable(void) -> void {

	for(auto [ addr, bytes ] : patches) {

		patchBytes((void*)addr, bytes);

	};

};