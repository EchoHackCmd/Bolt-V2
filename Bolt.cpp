#include "Client/Client.h"

auto init(void) -> void {

    auto client = new Client("Bolt-V2");

};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpRes) {

    switch(fdwReason) {

        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);
        break;

    };

    return TRUE;

};