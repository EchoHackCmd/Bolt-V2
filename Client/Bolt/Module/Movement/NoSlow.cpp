#include "NoSlow.h"
#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto NoSlow::onEnable(void) -> void {

	if(this->patches.empty()) {

		std::vector<uintptr_t> addresses = {
			
			Utils::findSig("F3 0F 11 46 ? 45 89 2E"),

			Utils::findSig("F3 0f 11 4E ? F3 0f 59 46"),
			
			Utils::findSig("F3 0f 11 4E ? F3 44 0F 10 46"),
			
			Utils::findSig("F3 0f 11 46 ? F3 0F 11 4E ? F3 44 0F 10 46"),
			
			Utils::findSig("F3 0f 11 40 ? 48 8B 07 48 8B CF FF 90 ? ? ? ? 48 8B 07"),
			
			Utils::findSig("F3 0f 11 48 ? f3 0f 10 05 ? ? ? ? F3 0F 11 40 ? 48 8B 07"),
			
			Utils::findSig("F3 0F 11 00 F3 0F 10 0D ? ? ? ? F3 0F 11 48 ? F3 0f 10 05 ? ? ? ? F3 0F 11 40 ? 48 8B 07")

		};

		for(auto addr : addresses) {

			auto bytes = getBytes((void*)addr, 5);
			this->patches[addr] = bytes;

		};

	};

	for(auto [ addr, bytes ] : this->patches) {

		nopBytes((void*)addr, bytes.size());

	};

};

auto NoSlow::onDisable(void) -> void {

	for(auto [ addr, bytes ] : this->patches) {

		patchBytes((void*)addr, bytes);

	};

};