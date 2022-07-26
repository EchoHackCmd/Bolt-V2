#include "TestModule.h"

#include "../../Category/Category.h"
#include "../../Manager.h"

auto TestModule::onTick(void) -> void {

    this->tickInt++;

    if(this->tickInt >= 100)
        this->category->manager->isRunning = false;
    
    Util::debugLog( std::string( "Tick: " + std::to_string( this->tickInt ) ) );

};