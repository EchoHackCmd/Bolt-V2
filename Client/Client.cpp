#include "Client.h"

Client::Client(std::string name) {

    Utils::debugLog("Initializing with name: " + name);
    
    this->name = name;
    this->init();

};

auto Client::init(void) -> void {

    this->manager = new Manager(this);

};