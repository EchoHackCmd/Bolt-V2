#include "TestModule.h"

auto TestModule::onTick(void) -> void {

    this->tickInt++;

    if(this->tickInt > 100)
        return this->setState(false);
    
    Util::debugLog( std::string( "Tick: " + std::to_string( this->tickInt ) ) );

};