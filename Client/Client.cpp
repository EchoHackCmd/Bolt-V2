#include "Client.h"

Client::Client(std::string name) {

    Util::debugLog("Initializing with name: " + name);
    
    this->name = name;
    this->init();

};

auto Client::init(void) -> void {

    this->manager = new Manager(this);

};

auto Client::uninject(void) -> void {

    auto hMod = Util::getDll();

    FreeLibraryAndExitThread(hMod, 1);

};