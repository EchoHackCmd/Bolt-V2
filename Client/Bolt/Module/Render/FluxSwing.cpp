#include "FluxSwing.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto FluxSwing::onEnable(void) -> void {

	if(this->patches.empty()) {

		auto fluxSwingAddr = Utils::findSig("E8 ? ? ? ? 41 0F 28 C0 F3 41 0F 5C C1");
		auto bytes = getBytes((void*)fluxSwingAddr, 5);

		this->patches[fluxSwingAddr] = bytes;

	};

	for(auto [ addr, bytes ] : this->patches) {

		nopBytes((void*)addr, bytes.size());

	};

};

auto FluxSwing::onDisable(void) -> void {

	for(auto [ addr, bytes ] : this->patches) {

		patchBytes((void*)addr, bytes);

	};

};