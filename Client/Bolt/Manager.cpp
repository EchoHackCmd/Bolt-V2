#include "Manager.h"

#include "Category/Category.h"
#include "../Client.h"

Manager::Manager(Client* client) {

	this->client = client;
	client->manager = this;

	this->isRunning = true;

	this->initHooks();

	this->initCategories();
	this->initModules();
	this->baseTick();

};

#include "Hook/Hooks/ClientInstance/ClientInstance.h"
#include "Hook/Hooks/SwapChain/SwapChain.h"
#include "Hook/Hooks/GameMode/GameMode.h"
#include "Hook/Hooks/Entity/Entity.h"
#include "Hook/Hooks/Key/Key.h"

auto Manager::initHooks(void) -> void {
	
	if(MH_Initialize() == MH_OK) {

		new ClientInstance_Hook(this);
		new SwapChain_Hook(this);
		new GameMode_Hook(this);
		new Entity_Hook(this);
		new Key_Hook(this);

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

		this->isRunning = (this->client != nullptr ? this->client->manager != nullptr : false);

		for(auto [ type, category ] : this->categories) {

			category->baseTick();

		};

		Sleep(1);

	};

	kiero::shutdown();
	MH_Uninitialize();

	Sleep(100);
	
	FreeLibraryAndExitThread(Utils::getDll(), 1);

};

auto Manager::isUsingKey(uint64_t key) -> bool {

	for(auto [ currKey, isDown] : keyMap) {

		if(currKey == key && isDown)
			return true;

	};

	return false;

};

auto Manager::cleanEntityMap(void) -> void {

	auto instance = Minecraft::getClientInstance();
	
	auto player = (instance != nullptr ? instance->getLocalPlayer() : nullptr);
	auto level = (player != nullptr ? player->getLevel() : nullptr);

	if(level == nullptr)
		return this->entityMap.clear();
	
	for(auto [ runtimeId, entity] : this->entityMap) {

		if(level->getRuntimeEntity(runtimeId, false) == nullptr)
			this->entityMap.erase(runtimeId);

	};

};

auto Manager::getLocalPlayer(void) -> class Player* {

	for(auto [ runtimeId, entity ] : this->entityMap) {

		auto level = entity->getLevel();

		if(level == nullptr)
			continue;
		
		return level->getPrimaryLocalPlayer();

	};

	return nullptr;

};