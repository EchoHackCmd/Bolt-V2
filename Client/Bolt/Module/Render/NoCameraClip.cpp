#include "NoCameraClip.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto NoCameraClip::onEnable(void) -> void {
	
	if(this->patches.empty()) {

		auto cameraAddr = Utils::findSig("F3 44 0F 51 EA 45 0F 28 CD");
		auto bytes = getBytes((void*)cameraAddr, 5);

		this->patches[cameraAddr] = bytes;

	};

	for(auto [ addr, bytes ] : this->patches) {

		nopBytes((void*)addr, bytes.size());

	};

};

auto NoCameraClip::onDisable(void) -> void {
	
	for(auto [ addr, bytes ] : this->patches) {

		patchBytes((void*)addr, bytes);

	};

};