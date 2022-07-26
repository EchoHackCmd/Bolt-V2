#ifndef CLIENT_UTIL_UTILS
#define CLIENT_UTIL_UTILS

#include <filesystem>
#include <Windows.h>
#include <MinHook.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <Psapi.h>
#include <cassert>
#include <vector>
#include <map>

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

class Utils {
public:
	static auto getDll(void)->HMODULE;
	static auto getDebugDir(void)->std::string;
public:
	static auto debugLog(std::string) -> void;
	static auto findSig(const char* szSignature) -> uintptr_t;
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

#endif /* CLIENT_UTILS_UTILS */