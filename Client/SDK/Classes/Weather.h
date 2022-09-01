#ifndef CLIENT_SDK_CLASSES_WEATHER
#define CLIENT_SDK_CLASSES_WEATHER

#include "../../Utils/Utils.h"
//padding should be right double check maybe :)
class Weather {
private:
    char pad_0x8[0x44]; 

public:
    auto fogLevel -> float; 

private:
	char pad_0x0000[0x38];

public:
	auto isRaining -> bool;

private:
	char pad_0x0039[0xB];

public:
	auto isLightning -> bool;

private:
	char pad_0x0045[0x3];

public:
	auto lightningLevel -> float;
};

#endif /* CLIENT_SDK_CLASSES_WEATHER */