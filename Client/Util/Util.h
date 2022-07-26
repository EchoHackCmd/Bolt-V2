#ifndef CLIENT_UTIL_UTIL
#define CLIENT_UTIL_UTIL

#include <Windows.h>
#include <assert.h>
#include <string>

class Util {
public:
    static auto getDll(void) -> HMODULE;
};

#endif /* CLIENT_UTIL_UTIL */