#ifndef CLIENT_SDK_CLASSES_GUIDATA
#define CLIENT_SDK_CLASSES_GUIDATA

#include "../../Utils/Utils.h"

class GuiData {
private:
    char pad_0000[48];      //0x0000
public:
    Vec2<float> screenRes1; //0x0030
    Vec2<float> screenRes2; //0x0038
    Vec2<float> screenRes3; //0x0040
private:
    char pad_0048[4];       //0x0048
public:
    float uiScale;          //0x004C
};

#endif /* CLIENT_SDK_CLASSES_GUIDATA */