#include "Module.h"

#include "../Manager.h"
#include "../Category/Category.h"

Module::Module(std::string name, Category* category) {

    this->name = name;
    this->category = category;
    this->category->addModule(this);

};

auto Module::setState(bool state) -> void {

    this->isEnabled = state;

};

auto Module::setKey(uint64_t key) -> void {

    this->key = key;

};


/* Module Mem Patching */

auto Module::getBytes(void* src, unsigned int bytes) -> std::vector<BYTE> {

    auto res = std::vector<BYTE>();

    for(auto I = 0; I < bytes; I++) {

        res.push_back(*(BYTE*)((uintptr_t)(src) + I));

    };

    return res;

};

auto Module::patchBytes(void* src, std::vector<BYTE> bytes) -> void {

    DWORD oldprotect;
    
    VirtualProtect(src, bytes.size(), PAGE_EXECUTE_READWRITE, &oldprotect);

    for(auto I = 0; I < bytes.size(); I++) {

        *(BYTE*)((uintptr_t)(src) + I) = bytes.at(I);

    };
    
    VirtualProtect(src, bytes.size(), oldprotect, &oldprotect);

};

auto Module::nopBytes(void* src, unsigned int bytes) -> void {

    DWORD oldprotect;
    VirtualProtect(src, bytes, PAGE_EXECUTE_READWRITE, &oldprotect);
    
    memset(src, 0x90, bytes);

    VirtualProtect(src, bytes, oldprotect, &oldprotect);

};