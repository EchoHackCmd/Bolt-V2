#include "TestModule.h"

#include "../../Category/Category.h"
#include "../../Manager.h"

auto TestModule::onTick(void) -> void {

    this->tickInt++;

    if(this->tickInt >= 100) {

        auto mgr = this->category->manager;

        for(auto [ type, category ] : mgr->categories) {

            auto cat = mgr->getCategory(type).second;

            if(cat == nullptr)
                Util::debugLog(category->getName());
            else
                Util::debugLog(cat->getName());

        };

        this->setState(false);
        this->category->manager->isRunning = false;

    };
    
    Util::debugLog( std::string( "Tick: " + std::to_string( this->tickInt ) ) );

};