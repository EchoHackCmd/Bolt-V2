#include "Client/Client.h"
#include <Windows.h>

auto init(HMODULE hMod) -> void {

    auto client = new Client("Bolt-V2");

    Sleep(5000);
    FreeLibraryAndExitThread(hMod, 1);

};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) {

    switch(fdwReason) {

        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);
        break;

    };

    return TRUE;

};