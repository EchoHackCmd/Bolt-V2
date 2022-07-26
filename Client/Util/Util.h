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
public:
	//this is from floppy ty :)
	static inline void nopBytes(void* dst, unsigned int size) {
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memset(dst, 0x90, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	};
	static inline void copyBytes(void* src, void* dst, unsigned int size) {
		DWORD oldprotect;
		VirtualProtect(src, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memcpy(dst, src, size);
		VirtualProtect(src, size, oldprotect, &oldprotect);
	};
	static inline void patchBytes(void* dst, void* src, unsigned int size) {
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memcpy(dst, src, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	};
};

#endif /* CLIENT_UTIL_UTIL */