#ifndef CLIENT_UTIL_UTIL
#define CLIENT_UTIL_UTIL

#include <filesystem>
#include <Windows.h>
#include <assert.h>
#include <fstream>
#include <string>

class Util {
public:
    static auto getDll(void) -> HMODULE;
    static auto getDebugDir(void) -> std::string;
public:
    static auto debugLog(std::string) -> void;
};

#endif /* CLIENT_UTIL_UTIL */