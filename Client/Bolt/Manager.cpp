#include "Manager.h"
#include "Category/Category.h"

Manager::Manager(Client* client) {
	
	this->client = client;
	this->isRunning = true;

	this->initHooks();

	this->initCategories();
	this->initModules();
	this->baseTick();

};

#include "Hook/Hooks/SwapChain/SwapChain.h"

auto Manager::initHooks(void) -> void {
	
	if(MH_Initialize() == MH_OK) {

		new SwapChain_Hook(this);

	} else {

		Utils::debugLog("MinHook failed to initialize!");

	};

};

auto Manager::initCategories(void) -> void {
	
	for(auto First = (int)CategoryType::Combat; First <= (int)CategoryType::Other; First++) {

		CategoryType currType = static_cast<CategoryType>(First);
		this->categories[currType] = new Category(currType, this);

		Utils::debugLog("Category Initialized: " + this->categories[currType]->getName());

	};

};

auto Manager::getCategory(CategoryType type) -> std::pair<std::string, Category*> {

	auto res = std::string("Unknown");
	
	switch(type) {

		case CategoryType::Combat:
			res = "Combat";
		break;

		case CategoryType::Movement:
			res = "Movement";
		break;

		case CategoryType::Player:
			res = "Player";
		break;

		case CategoryType::Render:
			res = "Render";
		break;

		case CategoryType::World:
			res = "World";
		break;

		case CategoryType::Other:
			res = "Other";
		break;

	};

	return std::pair<std::string, Category*>(res, (res.rfind("Unknown") == std::string::npos ? this->categories[type] : nullptr));

};

#include "Module/Other/TestModule.h"

auto Manager::initModules(void) -> void {
	
	/* Combat */

		
		
		/* WIP */

	
	
	/* Movement */

		
		
		/* WIP */
	
	
	
	/* Player */

		
		
		/* WIP */
	
	
	
	/* Render */

		
		
		/* WIP */
	

	
	/* World */

		
		
		/* WIP */

	
	
	/* Other */

	
	new TestModule(this->categories[CategoryType::Other]);
	

};

auto Manager::baseTick(void) -> void {

	while(this->isRunning) {

		for(auto [ type, category ] : this->categories) {

			category->baseTick();

		};

		Sleep(1);

	};

	MH_DisableHook(MH_ALL_HOOKS);
	
	Sleep(100);

	MH_Uninitialize();
	FreeLibraryAndExitThread(Utils::getDll(), 1);

};