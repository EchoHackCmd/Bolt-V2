#include "Client.h"

Client::Client(std::string name) {

    Utils::debugLog("Initializing with name: " + name);
    
    this->name = name;
    
    new Manager(this);

};