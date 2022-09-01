#ifndef CLIENT_SDK_CLASSES_DIMENSION
#define CLIENT_SDK_CLASSES_DIMENSION

#include "../../Utils/Utils.h"
#include "Weather.h"

class Dimension {
private:
	char pad_0x0[0xB8];  

public:
	auto maxHeight -> __int16; 

private:
	char pad_0x5E[0x5A];  

public:
	auto *brightnessRamp -> class BrightnessRamp; 

private:
    char pad_0xC0[0x90]; 

public:
	auto dimensionId -> int;  

private:
    char pad_0x154[0x1]; 

public:
	auto hasCeiling -> bool;  

private:
    char pad_0x156[0x2]; 

public:
	auto timeThingy -> int;  

private:
    char pad_0x15C[0x34]; 

public:
	auto *weather -> class Weather; 
};

#endif /* CLIENT_SDK_CLASSES_DIMENSION */