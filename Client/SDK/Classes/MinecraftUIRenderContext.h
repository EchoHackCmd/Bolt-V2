#ifndef CLIENT_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT
#define CLIENT_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT

#include "../../Utils/Utils.h"

class Rect : public Vec4<float> {
public:
    Rect(float top = 0.f, float left = 0.f, float right = 0.f, float bottom = 0.f){
        this->x = top;
        this->y = left;
        this->z = right;
        this->w = bottom;
    };
};

class Color : public Vec4<float> {
public:
    Color(float r = 0.f, float g = 0.f, float b = 0.f, float a = 1.f){
        this->x = r / 255.f;
        this->y = g / 255.f;
        this->z = b / 255.f;
        this->w = a / 255.f;
    };

    Color(){
        this->x = 0.f;
        this->y = 0.f;
        this->z = 0.f;
        this->w = 1.f;
    };
};

class TextAlignment;

struct TextMeasureData {
    float scale;

    TextMeasureData(){
        this->scale = 1.0f;
    };

    TextMeasureData(float scale){
        this->scale = scale;
    };
};

struct CaretMeasureData {
    int a;
    int b;

    CaretMeasureData(){
        CaretMeasureData(0xFFFFFFFF, false);
    };

    CaretMeasureData(int paramA, bool paramB){
        this->a = paramA;
        this->b = paramB;
    };
};

class ClientInstance;
class Font;

class MinecraftUIRenderContext {
public:
    ClientInstance* clientInstance;
private:
    virtual ~MinecraftUIRenderContext();
public:
    virtual auto getLineLength(Font*, std::string*, float, bool) -> float;
    virtual auto getTextAlpha(void) -> float;
    virtual auto setTextAlpa(float) -> void;
    virtual auto drawDebugText(Rect*, std::string*, Color*, float, unsigned int, float*, void*) -> __int64;
    virtual auto drawText(Font*, Rect*, std::string*, Color*, float, TextAlignment*, TextMeasureData*, CaretMeasureData*) -> __int64;
    virtual auto flushText(float) -> void;
private:
    virtual auto Function7(void) -> void;
    virtual auto Function8(void) -> void;
    virtual auto Function9(void) -> void;
    virtual auto Function10(void) -> void;
    virtual auto Function11(void) -> void;
public:
    virtual auto drawRectangle(Vec4<float>, Color, float, int) -> void;
    virtual auto fillRectangle(Vec4<float>, Color, float) -> void;
};

class MCRenderer {
private:
    static MinecraftUIRenderContext* ctx;
public:
    static auto setContext(MinecraftUIRenderContext*) -> void;
    static auto getContext(void) -> MinecraftUIRenderContext*;
public:
    static auto getFont(void) -> Font*;
public:
    static auto drawText(std::string, Vec2<float>, Color, float) -> void;
};

#endif /* CLIENT_SDK_CLASSES_MINECRAFTUIRENDERCONTEXT */