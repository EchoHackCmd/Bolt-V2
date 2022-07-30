#include "Criticals.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto criticalsAddress = (void*)(Utils::findSig("73 5A 80 B9 D8 01 ? ? ? 75 51"));
char ogCrits[9] = {};

auto Criticals::onEnable(void) -> void {

	if (criticalsAddress != nullptr) {
		
		Utils::copyBytes(criticalsAddress, ogCrits, 9);
		Utils::nopBytes(criticalsAddress, 9);
	
	};

};

auto Criticals::onDisable(void) -> void {
	
	Utils::patchBytes(criticalsAddress, ogCrits, 9);
	
};