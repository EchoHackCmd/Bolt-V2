#include "Criticals.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto Criticals::onEnable(void) -> void {

	if(this->patches.empty()) {

		auto critsAddr = Utils::findSig("73 5A 80 B9 D8 01 ? ? ? 75 51");
		auto bytes = getBytes((void*)critsAddr, 9);

		this->patches[critsAddr] = bytes;

	};

	for(auto [ addr, bytes ] : this->patches) {

		nopBytes((void*)addr, bytes.size());

	};

};

auto Criticals::onDisable(void) -> void {
	
	for(auto [ addr, bytes ] : this->patches) {

		patchBytes((void*)addr, bytes);

	};
	
};