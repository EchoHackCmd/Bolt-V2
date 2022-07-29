#include "NoCameraClip.h"

#include "../../Category/Category.h"
#include "../../../Client.h"
#include "../../Manager.h"

void* CameraAddr = (void*)(Utils::findSig("f3 44 0f 51 ea 45 0f 28 cd"));
char ogCam[5] = {};

auto NoCameraClip::onEnable(void) -> void {
	
	if(CameraAddr == nullptr)
		return;
	
	Utils::copyBytes(CameraAddr, ogCam, 5);
	Utils::nopBytes(CameraAddr, 5);

};

auto NoCameraClip::onDisable(void) -> void{
	
	Utils::patchBytes(CameraAddr, ogCam, 5);

};