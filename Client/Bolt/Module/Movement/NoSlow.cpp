#include "NoSlow.h"
#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

auto noSlowAddr1 = (void*)(Utils::findSig("f3 0f 11 46 ? 45 89 2e"));
char ogSlow1[5] = {};
auto noSlowAddr2 = (void*)(Utils::findSig("f3 0f 11 46 ? f3 0f 11 4e ? f3 44 0f 10 46"));
char ogSlow2[5] = {};
auto noSlowAddr3 = (void*)(Utils::findSig("f3 0f 11 4e ? f3 0f 59 46"));
char ogSlow3[5] = {};
auto noSlowAddr4 = (void*)(Utils::findSig("f3 0f 11 4e ? f3 44 0f 10 46"));
char ogSlow4[5] = {};
auto noSlowAddr5 = (void*)(Utils::findSig("f3 0f 11 40 ? 48 8b 07 48 8b cf ff 90 ? ? ? ? 48 8b 07"));
char ogSlow5[5] = {};
auto noSlowAddr6 = (void*)(Utils::findSig("f3 0f 11 48 ? f3 0f 10 05 ? ? ? ? f3 0f 11 40 ? 48 8b 07"));
char ogSlow6[5] = {};
auto noSlowAddr7 = (void*)(Utils::findSig("f3 0f 11 00 f3 0f 10 0d ? ? ? ? f3 0f 11 48 ? f3 0f 10 05 ? ? ? ? f3 0f 11 40 ? 48 8b 07"));
char ogSlow7[5] = {};

auto NoSlow::onEnable(void) -> void {
	if (
		noSlowAddr1 == nullptr
	||
		noSlowAddr2 == nullptr
	||
		noSlowAddr3 == nullptr
	||
		noSlowAddr4 == nullptr
	||
		noSlowAddr5 == nullptr
	||
		noSlowAddr6 == nullptr
	||
		noSlowAddr7 == nullptr
	)
		return this->setState(false);
	
	Utils::copyBytes(noSlowAddr1, ogSlow1, 5);
	Utils::copyBytes(noSlowAddr2, ogSlow2, 5);
	Utils::copyBytes(noSlowAddr3, ogSlow3, 5);
	Utils::copyBytes(noSlowAddr4, ogSlow4, 5);
	Utils::copyBytes(noSlowAddr5, ogSlow5, 5);
	Utils::copyBytes(noSlowAddr6, ogSlow6, 5);
	Utils::copyBytes(noSlowAddr7, ogSlow7, 5);
	Utils::nopBytes(noSlowAddr1, 5);
	Utils::nopBytes(noSlowAddr2, 5);
	Utils::nopBytes(noSlowAddr3, 5);
	Utils::nopBytes(noSlowAddr4, 5);
	Utils::nopBytes(noSlowAddr5, 5);
	Utils::nopBytes(noSlowAddr6, 5);
	Utils::nopBytes(noSlowAddr7, 5);

};

auto NoSlow::onDisable(void) -> void {
	
	Utils::patchBytes(noSlowAddr1, ogSlow1, 5);
	Utils::patchBytes(noSlowAddr2, ogSlow2, 5);
	Utils::patchBytes(noSlowAddr3, ogSlow3, 5);
	Utils::patchBytes(noSlowAddr4, ogSlow4, 5);
	Utils::patchBytes(noSlowAddr5, ogSlow5, 5);
	Utils::patchBytes(noSlowAddr6, ogSlow6, 5);
	Utils::patchBytes(noSlowAddr7, ogSlow7, 5);

};